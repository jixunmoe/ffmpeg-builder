ffmpeg builder
==============

A docker image to build ffmpeg.

Instructions taken from: https://trac.ffmpeg.org/wiki/CompilationGuide/Ubuntu

## Build docker image locally

```sh
docker build . --build-arg BUILD_ARCH=native --tag jixun/ffmpeg-builder:latest
```

Running above code should produce a natively optimised copy of ffmpeg dependencies.
For a generic build, use the following instead:

```sh
docker build . --tag jixun/ffmpeg-builder:latest
```
