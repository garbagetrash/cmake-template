CMake Template
==============

Quick template demonstrating how to setup CMake to build C modules with
libraries both built from source in a subdirectory, and precompiled and
statically linked.

Build with:

``` bash
$ mkdir build && cd build && cmake .. && make
```

Cross Compilation
=================

Cross compile with the following modification to the `cmake` call:

``` bash
$ cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-aarch64-linux-gnu.cmake ..
```

Testing
=======

Normal builds can be tested with a simple:

``` bash
$ make test
```

in the `build/` directory.

Cross compilation output test binaries can be verified using QEMU.  Install
QEMU for aarch64 and run:

``` bash
$ qemu-aarch64 -L <path/to/aarch64-gnu-linux/toolchain> <test_binary>
```

A specific example would be as follows:

``` bash
$ qemu-aarch -L /usr/aarch64-gnu-linux/ test_null
```
