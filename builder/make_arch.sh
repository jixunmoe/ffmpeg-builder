#!/bin/sh

set -ex

# get current cpu arch:
# cat /sys/devices/cpu/caps/pmu_name
# gcc -march=native -Q --help=target | awk '/march/ {print $2}'

for BUILD_ARCH in x86-64 broadwell silvermont znver2; do
  INPUT_FILE=Dockerfile.gcc-10
  OUTPUT_FILE="${INPUT_FILE}.${BUILD_ARCH}"
  sed "s/\(C\(XX\)\?FLAGS\)=\"/\1=\"-march=${BUILD_ARCH} /" < "$INPUT_FILE" > "$OUTPUT_FILE"
done
