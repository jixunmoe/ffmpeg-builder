# Ubuntu 20.04
FROM ubuntu:focal-20200703

ENV CC=clang
ENV CXX=clang
ENV LD=ld.lld
ENV PKG_CONFIG_PATH=/usr/lib64/pkgconfig:/usr/lib/pkgconfig
ENV DEBIAN_FRONTEND=noninteractive

# Update packages
RUN apt-get update -qq && apt-get -y install \
  autoconf \
  automake \
  clang-10 \
  lld-10 \
  cmake \
  git-core \
  libc6-dev \
  libfontconfig1-dev \
  libfreetype6-dev \
  libmp3lame-dev \
  libnuma-dev \
  libopus-dev \
  libtool \
  libvpx-dev \
  make \
  nasm \
  pkg-config \
  python3-minimal \
  texinfo \
  wget \
  yasm \
  zlib1g-dev \
  && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /build && \
  cd /build && \
  mkdir -p src tmp bin lib

WORKDIR /build/lib

### libass

RUN wget -q https://github.com/fribidi/fribidi/releases/download/v1.0.9/fribidi-1.0.9.tar.xz \
  && tar xf fribidi-1.0.9.tar.xz \
  && cd fribidi-1.0.9 \
  && ./configure --prefix=/usr --enable-static \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/fribidi-1.0.9 /build/lib/fribidi-1.0.9.tar.xz

RUN wget -q https://github.com/silnrsi/graphite/releases/download/1.3.14/graphite2-1.3.14.tgz \
  && tar xf graphite2-1.3.14.tgz \
  && cd graphite2-1.3.14 \
  && cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX:PATH=/usr . \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/graphite2-1.3.14 /build/lib/graphite2-1.3.14.tgz

RUN wget -q https://github.com/libass/libass/releases/download/0.14.0/libass-0.14.0.tar.xz \
  && tar xf libass-0.14.0.tar.xz \
  && cd libass-0.14.0 \
  && ./configure --prefix=/usr --enable-static \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/libass-0.14.0 /build/lib/libass-0.14.0.tar.xz

### fdk-aac

RUN wget -q https://github.com/mstorsjo/fdk-aac/archive/v2.0.1.tar.gz -O fdk-aac-2.0.1.tar.gz \
  && tar xf fdk-aac-2.0.1.tar.gz \
  && cd fdk-aac-2.0.1 \
  && autoreconf -fiv \
  && ./configure --prefix=/usr --enable-static \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/fdk-aac-2.0.1 /build/lib/fdk-aac-2.0.1.tar.gz

### x264 & x265

RUN git clone --branch stable --depth 1 https://code.videolan.org/videolan/x264.git x264-stable \
  && cd x264-stable \
  && ./configure \
    --prefix=/usr \
    --enable-static \
    --enable-pic \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/x264-stable

RUN wget -q https://bitbucket.org/multicoreware/x265/downloads/x265_3.4.tar.gz \
  && tar xf x265_3.4.tar.gz \
  && cd x265_3.4/build/linux \
  && cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/usr -DENABLE_SHARED=off ../../source \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/x265_3.4 /build/lib/x265_3.4.tar.gz

### libvorbis

RUN wget -q https://downloads.xiph.org/releases/ogg/libogg-1.3.4.tar.xz \
  && tar xf libogg-1.3.4.tar.xz \
  && cd libogg-1.3.4 \
  && ./configure \
    --prefix=/usr \
    --enable-static \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/libogg-1.3.4 /build/lib/libogg-1.3.4.tar.xz

RUN wget -q https://downloads.xiph.org/releases/vorbis/libvorbis-1.3.7.tar.xz \
  && tar xf libvorbis-1.3.7.tar.xz \
  && cd libvorbis-1.3.7 \
  && ./configure \
    --prefix=/usr \
    --enable-static \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/libvorbis-1.3.7 /build/lib/libvorbis-1.3.7.tar.xz

### gnutls

RUN wget -q https://gmplib.org/download/gmp/gmp-6.2.0.tar.xz \
  && tar xf gmp-6.2.0.tar.xz \
  && cd gmp-6.2.0 \
  && ./configure --prefix=/usr --enable-static \
  && make -j$(nproc) all \
  && make check \
  && make install \
  && rm -rf /build/lib/gmp-6.2.0 /build/lib/gmp-6.2.0.tar.xz

RUN wget -q https://ftp.gnu.org/gnu/nettle/nettle-3.6.tar.gz \
  && tar xf nettle-3.6.tar.gz \
  && cd nettle-3.6 \
  && ./.bootstrap \
  && ./configure --prefix=/usr --enable-static \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/nettle-3.6 /build/lib/nettle-3.6.tar.gz

# libdane: DNSSEC/DANE?
# p11: hardware related dependency?
ENV PKG_CONFIG_PATH=/usr/lib64/pkgconfig:/usr/lib/pkgconfig
RUN wget -q https://www.gnupg.org/ftp/gcrypt/gnutls/v3.6/gnutls-3.6.13.tar.xz \
  && tar xf gnutls-3.6.13.tar.xz \
  && cd gnutls-3.6.13 \
  && ./configure \
    --prefix=/usr \
    --enable-static \
    --disable-libdane \
    --with-included-libtasn1 \
    --with-included-unistring \
    --without-p11-kit \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/gnutls-3.6.13 /build/lib/gnutls-3.6.13.tar.xz

### libbluray

RUN git clone --branch v2.9.10 --depth 1 https://gitlab.gnome.org/GNOME/libxml2.git libxml2-2.9.10 \
  && cd libxml2-2.9.10 \
  && sh autogen.sh \
    --prefix=/usr \
    --enable-static \
    --without-python \
    --without-zlib \
    --without-lzma \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/libxml2-2.9.10

RUN wget -q https://download.videolan.org/pub/videolan/libbluray/1.1.2/libbluray-1.1.2.tar.bz2 \
  && tar xf libbluray-1.1.2.tar.bz2 \
  && cd libbluray-1.1.2 \
  && ./configure \
    --prefix=/usr \
    --enable-static \
    --disable-bdjava-jar \
  && make -j$(nproc) all \
  && make install \
  && rm -rf /build/lib/libbluray-1.1.2 /build/lib/libbluray-1.1.2.tar.bz2

VOLUME /build/bin

COPY build /usr/local/bin/build
COPY clang /usr/local/bin/clang

ENTRYPOINT [ "/usr/local/bin/build" ]
