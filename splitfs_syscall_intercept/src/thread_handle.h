#ifndef __NV_THREAD_HANDLER_H_
#define __NV_THREAD_HANDLER_H_

#include <pthread.h>
#include <stdatomic.h>
#include "file.h"
#include "lru_cache.h"
#include "timers.h"

pthread_t bgthread;
pthread_cond_t bgsignal;
pthread_mutex_t mu;

uint64_t lim_dr_mem_closed;
uint64_t lim_num_files;
uint64_t lim_dr_mem;

int run_background_thread;
int started_bgthread;
int exit_bgthread;
int calledBgThread;
int waiting_for_signal;
int cleanup;

pthread_spinlock_t      global_lock_closed_files;
pthread_spinlock_t      global_lock;

static void activateBgThread() {

	pthread_mutex_lock(&mu);

	run_background_thread = 1;
	pthread_cond_signal(&bgsignal);
	
	pthread_mutex_unlock(&mu);	

	//bgCloseFiles();
}

void waitForBgThread() {
	if(started_bgthread) {
		pthread_join(bgthread, NULL);
	}
}

void cancelBgThread() {
	if(started_bgthread) {
		pthread_cancel(bgthread);
		pthread_testcancel();
	}
}

void initEnvForBg() {	
	pthread_cond_init(&bgsignal, NULL);
	pthread_mutex_init(&mu, NULL);
}

void checkAndActivateBgThread() {
	if(run_background_thread)
		return;	
	if(dr_mem_closed_files > lim_dr_mem_closed || num_files_closed > lim_num_files || cleanup) {
		calledBgThread++;
		activateBgThread();	
	}
}

#endif
