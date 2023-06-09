# QCAMON - A framework to patch binaries of Xtensa based Qualcomm Wifi chips
Based on NEXMON: https://nexmon.org

# Instructions to compile patches
## Prerequisites
* `build-essential` or similar
* `gawk`
* `libdebuginfod-dev`
* `glibc` >= 2.36 (e.g. in Ubuntu 23.04)
* `bc`
## Instructions
* set environment variables: `source setup_env.sh`
* prepare firmware file and unpack prebuild GCC & binutils:
  * `make`
* compile firmware patches
  * for "hello world" of IPQ4019 `cd patches/qca4019/10.4_3.6_00140/hello_world/`
  * `make`
  * copy `firmware-5.bin` to your target device

# Optional: Build GCC yourself
## Prerequisites
* ...
## Instructions
* Do _not_ set QCAMON environment variables
* `cd buildtools/espressif-esp32-gcc`
* `make -f Makefile.self_compile`
* `make -f Makefile.self_compile install`
* Copy binutils files into the new GCC folder: `todo`
* Continue as described above

# Optional: Build Binutls yourself
## Prerequisites
* `texinfo`
## Instructions
* Do _not_ set QCAMON environment variables
* `cd buildtools/espressif-esp32-gcc`
* `make -f Makefile.self_compile`
* `make -f Makefile.self_compile install`
* set environment variables from root directory: `source ../../setup_env.sh`
* `make -f Makefile.self_compile install-to-gcc`
* Continue as described above

# Disassembler patches
## Binary Ninja
* Patch is based on: https://github.com/zackorndorff/binja-xtensa
* Commit which is known to work: `e4d61b1a92f0af9990f77c66381a3ca6e281155f`
* Clone the repository into the Ninja plugins directory
* Apply patch: https://github.com/DanielAW/qcamon/blob/main/disassembler_patches/binary_ninja.patch

## Ghidra
* Patch is based on https://github.com/Ebiroll/ghidra-xtensa
* Commit which is known to work `4e1aa22f76b6350d018094dfedeefe4b9096d9e1`
* For installation follow instrutions on the github page of the plugin linked above
* Apply patch: https://github.com/DanielAW/qcamon/blob/main/disassembler_patches/ghidra.patch
