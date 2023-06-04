# QCAMON - A framework to patch binaries of Xtensa based Qualcomm Wifi chips
Based on NEXMON: https://nexmon.org

# Instructions to compile patches
* set environment variables: `source setup_env.sh`
* ...

# Build GCC yourself
## Prerequisites
* ...
## Instructions
* Do _not_ set QCAMON environment variables
* `cd buildtools/espressif-esp32-gcc`
* `make -f Makefile.self_compile`
* `make -f Makefile.self_compile install`
* Copy binutils files into the new GCC folder: `todo`
* Continue as described above
