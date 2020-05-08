# Ubuntu 18.04
FROM ubuntu:bionic-20200311

ENV DEBIAN_FRONTEND=noninteractive

# Update packages
RUN apt-get update -qq && apt-get -y install \
  autoconf \
  automake \
  build-essential \
  cmake \
  git-core \
  libfontconfig1-dev \
  libfreetype6-dev \
  libmp3lame-dev \
  libnuma-dev \
  libopus-dev \
  libtool \
  libvorbis-dev \
  libvpx-dev \
  libx264-dev \
  nasm \
  pkg-config \
  python3 \
  texinfo \
  wget \
  yasm \
  zlib1g-dev \
  && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /build
WORKDIR /build

RUN mkdir -p src tmp bin lib

WORKDIR /build/lib

### libass

RUN wget -q https://github.com/fribidi/fribidi/releases/download/v1.0.9/fribidi-1.0.9.tar.xz \
  && tar xf fribidi-1.0.9.tar.xz \
  && cd fribidi-1.0.9 \
  && ./configure --prefix=/usr --enable-static \
  && make -j4 all \
  && make install \
  && rm -rf /build/lib/fribidi-1.0.9 /build/lib/fribidi-1.0.9.tar.xz

RUN wget -q https://github.com/silnrsi/graphite/releases/download/1.3.14/graphite2-1.3.14.tgz \
  && tar xf graphite2-1.3.14.tgz \
  && cd graphite2-1.3.14 \
  && cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX:PATH=/usr . \
  && make -j4 all \
  && make install \
  && rm -rf /build/lib/graphite2-1.3.14 /build/lib/graphite2-1.3.14.tgz

RUN wget -q https://github.com/libass/libass/releases/download/0.14.0/libass-0.14.0.tar.xz \
  && tar xf libass-0.14.0.tar.xz \
  && cd libass-0.14.0 \
  && ./configure --prefix=/usr --enable-static \
  && make -j4 all \
  && make install \
  && rm -rf /build/lib/libass-0.14.0 /build/lib/libass-0.14.0.tar.xz

### fdk-aac

RUN wget -q https://github.com/mstorsjo/fdk-aac/archive/v2.0.1.tar.gz -O fdk-aac-2.0.1.tar.gz \
  && tar xf fdk-aac-2.0.1.tar.gz \
  && cd fdk-aac-2.0.1 \
  && autoreconf -fiv \
  && ./configure --prefix=/usr --enable-static \
  && make -j4 all \
  && make install \
  && rm -rf /build/lib/fdk-aac-2.0.1 /build/lib/fdk-aac-2.0.1.tar.gz

### x265

RUN wget -q https://bitbucket.org/multicoreware/x265/downloads/x265_3.3.tar.gz \
  && tar xf x265_3.3.tar.gz \
  && cd x265_3.3/build/linux \
  && cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/usr -DENABLE_SHARED=off ../../source \
  && make -j4 all \
  && make install \
  && rm -rf /build/lib/x265_3.3 /build/lib/x265_3.3.tar.gz

### gnutls

RUN wget -q https://gmplib.org/download/gmp/gmp-6.2.0.tar.xz \
  && tar xf gmp-6.2.0.tar.xz \
  && cd gmp-6.2.0 \
  && ./configure --prefix=/usr --enable-static \
  && make -j4 all \
  && make check \
  && make install \
  && rm -rf /build/lib/gmp-6.2.0 /build/lib/gmp-6.2.0.tar.xz

RUN wget -q https://ftp.gnu.org/gnu/nettle/nettle-3.6.tar.gz \
  && tar xf nettle-3.6.tar.gz \
  && cd nettle-3.6 \
  && ./.bootstrap \
  && ./configure --prefix=/usr --enable-static \
  && make -j4 all \
  && make install \
  && rm -rf /build/lib/nettle-3.6 /build/lib/nettle-3.6.tar.gz

# libdane: DNSSEC/DANE?
# p11: hardware related dependency?
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
  && make -j4 all \
  && make install \
  && rm -rf /build/lib/gnutls-3.6.13 /build/lib/gnutls-3.6.13.tar.xz

VOLUME /build/bin

COPY build /usr/local/bin/build
COPY gcc /usr/local/bin/gcc

ENTRYPOINT [ "/usr/local/bin/build" ]
