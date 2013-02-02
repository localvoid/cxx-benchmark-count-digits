#!/bin/bash

BPATH=../build/

benchmarks=(
  naive
  cmp
  reverse_cmp
  range_case
  range_case2
  unroll4
  bchop
  bsearch
  bsr
)

modes=(
  "u64:20"
  "u32:10"
  "u16:5"
  "u8:3"
)


function mkgraph {
  ./graph.R < $1 $2
}

function preload {
  for m in ${modes[@]}; do
    MODE=${m%%:*}
    for i in ${benchmarks[@]};  do
      $BPATH$i 1 $MODE >> /dev/null
    done
  done
}

function cold_bench {
  echo "Generating cold digits10 data"
  echo "Size,Name,Digits,Time" > $1
  for m in ${modes[@]}; do
    MODE=${m%%:*}
    MODE_DIGITS=${m#*:}
    for x in {1..100}; do
      for i in ${benchmarks[@]}; do
        DIGITS=${MODE_DIGITS}
        while [ $DIGITS -gt 0 ]; do
          $BPATH$i 1 $MODE $DIGITS >> $1
          let DIGITS-=1
        done
      done
    done
  done
}

function hot_bench {
  echo "Generating hot digits10 data"
  echo "Size,Name,Digits,Time" > $1
  for m in ${modes[@]}; do
    MODE=${m%%:*}
    for x in {1..100}; do
      for i in ${benchmarks[@]}; do
        $BPATH$i 1000 $MODE >> $1
      done
    done
  done
}


preload

hot_bench "hot_digits10.csv"
mkgraph "hot_digits10.csv" "hot_digits10.pdf"

cold_bench "cold_digits10.csv"
mkgraph "cold_digits10.csv" "cold_digits10.pdf"
