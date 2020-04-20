# Ubuntu 18.04
FROM ubuntu:bionic-20200311

# Update packages
RUN apt update -qq && apt full-upgrade -y && apt -y install \
  autoconf \
  automake \
  build-essential \
  cmake \
  git-core \
  libfreetype6-dev \
  libsdl2-dev \
  libtool \
  libva-dev \
  libvdpau-dev \
  libvorbis-dev \
  libxcb1-dev \
  libxcb-shm0-dev \
  libxcb-xfixes0-dev \
  pkg-config \
  texinfo \
  wget \
  zlib1g-dev \
  nasm \
  yasm \
  libx264-dev \
  libnuma-dev \
  libvpx-dev \
  libmp3lame-dev \
  libopus-dev \
  && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /build
WORKDIR /build

RUN mkdir -p src tmp bin lib

WORKDIR /build/lib

RUN wget https://github.com/libass/libass/releases/download/0.14.0/libass-0.14.0.tar.xz \
  && tar xf libass-0.14.0.tar.xz \
  && cd libass-0.14.0 \
  && ./configure --prefix=/usr --enable-static \
  && make -j4 all install \
  && rm -rf /build/lib/libass-0.14.0 /build/lib/libass-0.14.0.tar.xz

RUN wget https://github.com/fribidi/fribidi/releases/download/v1.0.9/fribidi-1.0.9.tar.xz \
  && tar xf fribidi-1.0.9.tar.xz \
  && cd fribidi-1.0.9 \
  && ./configure --prefix=/usr --enable-static \
  && make -j4 all install \
  && rm -rf /build/lib/fribidi-1.0.9 /build/lib/fribidi-1.0.9.tar.xz

RUN wget https://github.com/silnrsi/graphite/releases/download/1.3.14/graphite2-1.3.14.tgz \
  && tar xf graphite2-1.3.14.tgz \
  && cd graphite2-1.3.14 \
  && cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX:PATH=/usr . \
  && make -j4 all install \
  && rm -rf /build/lib/graphite2-1.3.14 /build/lib/graphite2-1.3.14.tgz

RUN wget https://github.com/mstorsjo/fdk-aac/archive/v2.0.1.tar.gz -O fdk-aac-2.0.1.tar.gz \
  && tar xf fdk-aac-2.0.1.tar.gz \
  && cd fdk-aac-2.0.1 \
  && autoreconf -fiv \
  && ./configure --prefix=/usr --enable-static \
  && make -j4 all install \
  && rm -rf /build/lib/fdk-aac-2.0.1 /build/lib/fdk-aac-2.0.1.tar.gz

RUN wget https://bitbucket.org/multicoreware/x265/downloads/x265_3.3.tar.gz \
  && tar xf x265_3.3.tar.gz \
  && cd x265_3.3/build/linux \
  && cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/usr -DENABLE_SHARED=off ../../source \
  && make -j4 all install \
  && rm -rf /build/lib/x265_3.3 /build/lib/x265_3.3.tar.gz

VOLUME /build/bin

COPY build /usr/local/bin/build
COPY gcc /usr/local/bin/gcc

ENTRYPOINT [ "/usr/local/bin/build" ]
