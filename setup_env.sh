OLD_PWD=$(pwd)
cd $(dirname ${BASH_SOURCE[0]})

export ARCH=xtensa
#export SUBARCH=arm
#export KERNEL=kernel7

export HOSTUNAME=$(uname -s)
export PLATFORMUNAME=$(uname -m)

export NEXMON_ROOT=$(pwd)

export CC=$NEXMON_ROOT/buildtools/espressif-esp32-gcc/build-gcc-install/usr/bin/xtensa-esp32-elf-
export CCPLUGIN=$NEXMON_ROOT/buildtools/gcc-nexmon-plugin/nexmon.so
export ZLIBFLATE="zlib-flate -compress"

export Q=@
export NEXMON_SETUP_ENV=1

cd "$OLD_PWD"
