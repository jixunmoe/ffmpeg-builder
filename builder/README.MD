ffmpeg builder
==============

A docker image to build ffmpeg.

## Build ffmpeg

To build latest snapshot of ffmpeg:

```sh
mkdir -p bin
docker run -it -v "$(pwd)/bin:/build/bin" jixun:ffmpeg_builder
```
