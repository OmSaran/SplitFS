# Copyright (C) 2002-2018 Free Software Foundation, Inc.
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This file is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this file.  If not, see <https://www.gnu.org/licenses/>.
#
# As a special exception to the GNU General Public License,
# this file may be distributed as part of a program that
# contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.
#
# This file represents the specification of how gnulib-tool is used.
# It acts as a cache: It is written and read by gnulib-tool.
# In projects that use version control, this file is meant to be put under
# version control, like the configure.ac and various Makefile.am files.


# Specification in the form of a command-line invocation:
# gnulib-tool --import --local-dir=gl \
#  --lib=libgnu \
#  --source-base=gnu \
#  --m4-base=m4 \
#  --doc-base=doc \
#  --tests-base=tests \
#  --aux-dir=build-aux \
#  --no-conditional-dependencies \
#  --no-libtool \
#  --macro-prefix=gl \
#  --avoid=lock \
#  alloca \
#  areadlinkat-with-size \
#  argmatch \
#  argp \
#  argp-version-etc \
#  backupfile \
#  closeout \
#  configmake \
#  dirname \
#  error \
#  exclude \
#  exitfail \
#  extern-inline \
#  faccessat \
#  fchmodat \
#  fchownat \
#  fcntl-h \
#  fdopendir \
#  fdutimensat \
#  file-has-acl \
#  fileblocks \
#  fnmatch-gnu \
#  fprintftime \
#  fseeko \
#  fstatat \
#  full-write \
#  futimens \
#  getline \
#  getopt-gnu \
#  getpagesize \
#  gettext \
#  gettime \
#  gitlog-to-changelog \
#  hash \
#  human \
#  inttostr \
#  inttypes \
#  lchown \
#  linkat \
#  localcharset \
#  manywarnings \
#  mkdirat \
#  mkdtemp \
#  mkfifoat \
#  modechange \
#  obstack \
#  openat \
#  parse-datetime \
#  priv-set \
#  progname \
#  quote \
#  quotearg \
#  readlinkat \
#  renameat \
#  root-uid \
#  rpmatch \
#  safe-read \
#  savedir \
#  selinux-at \
#  setenv \
#  snprintf \
#  stat-time \
#  stdbool \
#  stdint \
#  stpcpy \
#  strdup-posix \
#  strerror \
#  strtoimax \
#  strtol \
#  strtoul \
#  strtoumax \
#  symlinkat \
#  timespec \
#  timespec-sub \
#  unlinkat \
#  unlinkdir \
#  unlocked-io \
#  utimensat \
#  version-etc-fsf \
#  xalloc \
#  xalloc-die \
#  xgetcwd \
#  xstrtoumax \
#  xvasprintf

# Specification in the form of a few gnulib-tool.m4 macro invocations:
gl_LOCAL_DIR([gl])
gl_MODULES([
  alloca
  areadlinkat-with-size
  argmatch
  argp
  argp-version-etc
  backupfile
  closeout
  configmake
  dirname
  error
  exclude
  exitfail
  extern-inline
  faccessat
  fchmodat
  fchownat
  fcntl-h
  fdopendir
  fdutimensat
  file-has-acl
  fileblocks
  fnmatch-gnu
  fprintftime
  fseeko
  fstatat
  full-write
  futimens
  getline
  getopt-gnu
  getpagesize
  gettext
  gettime
  gitlog-to-changelog
  hash
  human
  inttostr
  inttypes
  lchown
  linkat
  localcharset
  manywarnings
  mkdirat
  mkdtemp
  mkfifoat
  modechange
  obstack
  openat
  parse-datetime
  priv-set
  progname
  quote
  quotearg
  readlinkat
  renameat
  root-uid
  rpmatch
  safe-read
  savedir
  selinux-at
  setenv
  snprintf
  stat-time
  stdbool
  stdint
  stpcpy
  strdup-posix
  strerror
  strtoimax
  strtol
  strtoul
  strtoumax
  symlinkat
  timespec
  timespec-sub
  unlinkat
  unlinkdir
  unlocked-io
  utimensat
  version-etc-fsf
  xalloc
  xalloc-die
  xgetcwd
  xstrtoumax
  xvasprintf
])
gl_AVOID([ lock])
gl_SOURCE_BASE([gnu])
gl_M4_BASE([m4])
gl_PO_BASE([])
gl_DOC_BASE([doc])
gl_TESTS_BASE([tests])
gl_LIB([libgnu])
gl_MAKEFILE_NAME([])
gl_MACRO_PREFIX([gl])
gl_PO_DOMAIN([])
gl_WITNESS_C_MACRO([])
