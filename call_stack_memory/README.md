# show memory of call stack

## compile
```
$ mkdir build && cd build
$ cmake -DCMAKE_C_COMPILER=<compiler path> ..
$ make
```

## example(on MacOSX)

### gcc@4.9
```
$ cmake -DCMAKE_C_COMPILER=/usr/local/bin/gcc-4.9 .. && make
$ ./main
a: 0x7ffeedd1b23c b: 0x7ffeedd1b230 c: 0x7ffeedd1b238
size: 24
intlongint >
addr: 0x7ffeedd1b238
0x7ffeedd1b230:  02 00 00 00 00 00 00 00 03 00 00 00 01 00 00 00
0x7ffeedd1b240:  00 00 00 00 01 00 00 00 18 00 00 00 00 00 00 00

a: 0x7ffeedd1b23c b: 0x7ffeedd1b238 c: 0x7ffeedd1b230
size: 32
intintlong >
addr: 0x7ffeedd1b230
0x7ffeedd1b230:  03 00 00 00 00 00 00 00 02 00 00 00 01 00 00 00
0x7ffeedd1b240:  00 00 00 00 01 00 00 00 20 00 00 00 00 00 00 00

a: 0x7ffeedd1b238 b: 0x7ffeedd1b234 c: 0x7ffeedd1b230
size: 32
longintint >
addr: 0x7ffeedd1b230
0x7ffeedd1b230:  03 00 00 00 02 00 00 00 01 00 00 00 00 00 00 00
0x7ffeedd1b240:  00 00 00 00 01 00 00 00 20 00 00 00 00 00 00 00

a: 0x7ffeedd1b23c b: 0x7ffeedd1b230 c: 0x7ffeedd1b238
size: 24
intlongint >
addr: 0x7ffeedd1b238
0x7ffeedd1b230:  02 00 00 00 00 00 00 00 03 00 00 00 01 00 00 00
0x7ffeedd1b240:  00 00 00 00 01 00 00 00 18 00 00 00 00 00 00 00
```

### clang
```
$ cmake -DCMAKE_C_COMPILER=/usr/bin/clang .. && make
$ ./main
a: 0x7ffee932d24c b: 0x7ffee932d240 c: 0x7ffee932d23c
size: 20
intlongint >
addr: 0x7ffee932d23c
0x7ffee932d230:  14 00 00 00 00 00 00 00 88 d2 32 e9 03 00 00 00
0x7ffee932d240:  02 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00

a: 0x7ffee932d24c b: 0x7ffee932d248 c: 0x7ffee932d240
size: 16
intintlong >
addr: 0x7ffee932d240
0x7ffee932d240:  03 00 00 00 00 00 00 00 02 00 00 00 01 00 00 00

a: 0x7ffee932d248 b: 0x7ffee932d244 c: 0x7ffee932d240
size: 16
longintint >
addr: 0x7ffee932d240
0x7ffee932d240:  03 00 00 00 02 00 00 00 01 00 00 00 00 00 00 00

a: 0x7ffee932d24c b: 0x7ffee932d240 c: 0x7ffee932d23c
size: 20
intlongint >
addr: 0x7ffee932d23c
0x7ffee932d230:  14 00 00 00 00 00 00 00 10 00 00 00 03 00 00 00
0x7ffee932d240:  02 00 00 00 00 00 00 00 01 00 00 00 01 00 00 00
```
