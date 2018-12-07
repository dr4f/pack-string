# pack-string

*A Library for packing C++ objects into binary data.*

![language button](https://img.shields.io/badge/Language-C-orange.svg)
![build button](https://img.shields.io/badge/Build-passing-green.svg)

## Intro 

`pack-string` is a C++ library used for easily packing objects into binary format. It makes the process of fitting in C types, or C++ types, into an array of bytes simple and effecient. `pack-string` uses a special memory allocation scheme from the C standard library to optimize performance.

## Building

To Build `pack-string`, input the following commands in your terminal:

```
$ mkdir bin
$ cd bin
$ cmake ..
$ make
```

To run the unit tests, run `make test`:

```
$ make test
```


## Purpose

`pack-string` was developed primiarily as a utility for the `dr4` data storage format. C++ doesn't natively provide a byte packing class, or a string that can pack in bytes, so this library was developed to solve that problem.

[You can learn more about the dr4 format here.](https://github.com/dr4f)
