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

## Usage

`pack-string` is intended to be used as neat, concise interface for building binary formatted strings. The library contains two main classes:

1. `MallocArray`: A special vector-like class that uses `std::malloc` and `std::realloc`
2. `PackString`: A String object that packs objects into binary strings, and records their offsets in the string.

### Implementation

With `pack-string`, you can write implmentations for your custom objects to be packed into the `PackString` instance.

In order to this, you need a function signature of:

```cpp
void append_bytes(PackString& pstring, const Object& obj);
```

Where `Object` is a user defined class. Secondly, you need this declared as a `friend` function inside the class you want to use it for.

```cpp

class Object {
	...
	friend void append_bytes(PackString& pstring, const Object& obj);
};
```

Then, use the `append_bytes` function for implementing custom behavior to what attributes or order of `Object` should be packed in.


## Purpose

`pack-string` was developed primiarily as a utility for the `dr4` data storage format. C++ doesn't natively provide a byte packing class, or a string that can pack in bytes, so this library was developed to solve that problem.

[You can learn more about the dr4 format here.](https://github.com/dr4f)
