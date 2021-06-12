ffmpeg builder
==============

A docker image to build ffmpeg.

Instructions taken from: https://trac.ffmpeg.org/wiki/CompilationGuide/Ubuntu

## Build docker image locally

See readme at `builder` folder.

## Build ffmpeg

To build latest snapshot of ffmpeg:

```sh
mkdir -p bin
docker run --rm -v "$(pwd)/bin:/build/bin" jixun/ffmpeg-builder
```

To build a release (e.g. 4.4):

```sh
mkdir -p bin
docker run --rm -v "$(pwd)/bin:/build/bin" jixun/ffmpeg-builder 4.4
```

To build v4.4 using a pre-built docker image:

```sh
mkdir -p bin
docker run --rm -v "$(pwd)/bin:/build/bin" docker.pkg.github.com/jixunmoe/ffmpeg-builder/builder:gcc-10-x86-64 4.4
```

`-march` is available for the following:

* `x86-64` (generic)
* `silvermont`
* `broadwell`
* `znver2` (Ryzen)

e.g. for a Ryzen optimised build:

```sh
mkdir -p bin
docker run --rm -v "$(pwd)/bin:/build/bin" docker.pkg.github.com/jixunmoe/ffmpeg-builder/builder:gcc-10-znver2 4.4
```
