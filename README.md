CMake Template
==============

Quick template demonstrating how to setup CMake to build C modules with
libraries both built from source in a subdirectory, and precompiled and
statically linked.

Build with:

``` bash
$ mkdir build && cd build && cmake .. && make
```

Cross compile with the following modification to the `cmake` call:
``` bash
$ cmake -DCMAKE_TOOLCHAIN_FILE=../Toolchain-aarch64-linux-gnu.cmake ..
```
