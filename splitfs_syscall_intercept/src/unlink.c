/*
 * =====================================================================================
 *
 *       Filename:  unlink.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2019 03:22:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <libsyscall_intercept_hook_point.h>

#include <nv_common.h>
#include "nvp_lock.h"
#include "tbl_mmaps.h"
#include "timers.h"
#include "mmap_cache.h"
#include "inode.h"
#include "file.h"
#include "handle_mmaps.h"
#include "log.h"

RETT_SYSCALL_INTERCEPT _sfs_UNLINK(INTF_SYSCALL)
{
	struct stat file_st;
	int index, tbl_mmap_idx, over_tbl_mmap_idx;
	struct InodeToMapping* mappingToBeRemoved;
	instrumentation_type unlink_time, clf_lock_time, clear_mmap_tbl_time, op_log_entry_time;
	char *path;

	START_TIMING(unlink_t, unlink_time);
	GLOBAL_LOCK_WR();

	num_stat++;

	DEBUG("CALL: %s\n", __func__);
	path = (char *)arg0;

	if (stat(path, &file_st) == 0) {
		index = file_st.st_ino % OPEN_MAX;
		tbl_mmap_idx = file_st.st_ino % APPEND_TBL_MAX;
		struct NVTable_maps *tbl_app = &_nvp_tbl_mmaps[tbl_mmap_idx];

#if DATA_JOURNALING_ENABLED
		over_tbl_mmap_idx = file_st.st_ino % OVER_TBL_MAX;
		struct NVTable_maps *tbl_over = &_nvp_over_tbl_mmaps[over_tbl_mmap_idx];
#else
		struct NVTable_maps *tbl_over = NULL;
#endif // DATA_JOURNALING_ENABLED

		DEBUG_FILE("%s: Deleting file: %s. Inode = %lu\n", __func__, path, file_st.st_ino);

		START_TIMING(clear_mmap_tbl_t, clear_mmap_tbl_time);

		TBL_ENTRY_LOCK_WR(tbl_app);
		TBL_ENTRY_LOCK_WR(tbl_over);
		clear_tbl_mmap_entry(tbl_app, NUM_APP_TBL_MMAP_ENTRIES);

#if DATA_JOURNALING_ENABLED

		clear_tbl_mmap_entry(tbl_over, NUM_OVER_TBL_MMAP_ENTRIES);

#endif // DATA_JOURNALING_ENABLED

		TBL_ENTRY_UNLOCK_WR(tbl_over);
		TBL_ENTRY_UNLOCK_WR(tbl_app);
		END_TIMING(clear_mmap_tbl_t, clear_mmap_tbl_time);

		mappingToBeRemoved = &_nvp_ino_mapping[index];
		if(file_st.st_ino == mappingToBeRemoved->serialno && mappingToBeRemoved->root_dirty_num) {
			nvp_free_btree(mappingToBeRemoved->root, mappingToBeRemoved->merkle_root, mappingToBeRemoved->height, mappingToBeRemoved->root_dirty_cache, mappingToBeRemoved->root_dirty_num, mappingToBeRemoved->total_dirty_mmaps);
			mappingToBeRemoved->serialno = 0;
		}
	}
	num_unlink++;
	*result = syscall_no_intercept(SYS_unlink, path);

#if !POSIX_ENABLED
	if(*result == 0) {
		START_TIMING(op_log_entry_t, op_log_entry_time);
		persist_op_entry(LOG_FILE_UNLINK,
				path,
				NULL,
				0,
				0);
		END_TIMING(op_log_entry_t, op_log_entry_time);
	}
#endif

	END_TIMING(unlink_t, unlink_time);
	GLOBAL_UNLOCK_WR();
	return RETT_NO_PASS_KERN;
}

RETT_SYSCALL_INTERCEPT _sfs_UNLINKAT(INTF_SYSCALL)
{
	instrumentation_type op_log_entry_time;
	int dirfd, flags;
	char *path;

	DEBUG("CALL: _sfs_UNLINKAT\n");

	dirfd = (int)arg0;
	path = (char *)arg1;
	flags = (int)arg2;

	//GLOBAL_LOCK_WR();
	*result = syscall_no_intercept(SYS_unlinkat, dirfd, path, flags);

#if !POSIX_ENABLED
	START_TIMING(op_log_entry_t, op_log_entry_time);
	persist_op_entry(LOG_FILE_UNLINK,
			 path,
			 NULL,
			 0,
			 0);
	END_TIMING(op_log_entry_t, op_log_entry_time);
#endif
	return RETT_NO_PASS_KERN;
}
