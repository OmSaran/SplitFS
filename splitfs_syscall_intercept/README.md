1. cd src
2. make clean && make
3. LD_PRELOAD=./libnvp.so <program> -- relative to src directory

To run pjd test on this:
Run these as root user
1. cd <repo>/tests
2. make pjd.posix_sysint