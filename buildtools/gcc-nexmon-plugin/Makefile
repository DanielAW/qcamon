all: nexmon.so

nexmon.so: nexmon.o
	g++ -m64 -shared -o $@ $<

nexmon.o: nexmon.c
	g++ -std=c++11 -Wall -fno-rtti -Wno-literal-suffix -m64 -fPIC -I/usr/lib/gcc/xtensa-esp32-elf/12.2.0/plugin/include/ -I/data/qualcomm/qcamon/buildtools/xtensa-gcc/src/gcc-10.2.0/include -c -o $@ $<

clean:
	rm -f *.o *.so
