install-to-gcc: binutils-install
	cp binutils-install/usr/xtensa-esp32-elf/bin/as $(NEXMON_ROOT)/buildtools/espressif-esp32-gcc/build-gcc-install/usr/lib/gcc/xtensa-esp32-elf/12.2.0/
	cp binutils-install/usr/xtensa-esp32-elf/bin/ld $(NEXMON_ROOT)/buildtools/espressif-esp32-gcc/build-gcc-install/usr/bin/xtensa-esp32-elf-ld
	cp binutils-install/usr/xtensa-esp32-elf/bin/objdump $(NEXMON_ROOT)/buildtools/espressif-esp32-gcc/build-gcc-install/usr/bin/xtensa-esp32-elf-objdump
	cp binutils-install/usr/xtensa-esp32-elf/bin/objcopy $(NEXMON_ROOT)/buildtools/espressif-esp32-gcc/build-gcc-install/usr/bin/xtensa-esp32-elf-objcopy

binutils-install: 
	tar xfvz binutils-install.tar.gz

clean:
	rm -rf binutils-install
