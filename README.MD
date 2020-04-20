ffmpeg builder
==============

A docker image to build ffmpeg.

Instructions taken from: https://trac.ffmpeg.org/wiki/CompilationGuide/Ubuntu

## Build docker image locally

```sh
cd builder
docker build . --tag jixun/ffmpeg-builder
```

※ Should be available in [Docker Hub][hub], but is untagged.

[hub]: https://hub.docker.com/r/jixun/ffmpeg-builder

## Build ffmpeg

To build latest snapshot of ffmpeg:

```sh
mkdir -p bin
docker run -v "$(pwd)/bin:/build/bin" jixun/ffmpeg-builder
```
