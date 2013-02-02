#include <cstdint>
#include "benchmark.hpp"

const char *benchmark::name = "cmp";

enum : uint64_t {
  P01 = 10,
  P02 = 100,
  P03 = 1000,
  P04 = 10000,
  P05 = 100000,
  P06 = 1000000,
  P07 = 10000000,
  P08 = 100000000,
  P09 = 1000000000,
  P10 = 10000000000,
  P11 = 100000000000,
  P12 = 1000000000000,
  P13 = 10000000000000,
  P14 = 100000000000000,
  P15 = 1000000000000000,
  P16 = 10000000000000000,
  P17 = 100000000000000000,
  P18 = 1000000000000000000,
  P19 = 10000000000000000000U
};


uint32_t benchmark::digits10(uint64_t n) {
  if (n < P01) return 1;
  if (n < P02) return 2;
  if (n < P03) return 3;
  if (n < P04) return 4;
  if (n < P05) return 5;
  if (n < P06) return 6;
  if (n < P07) return 7;
  if (n < P08) return 8;
  if (n < P09) return 9;
  if (n < P10) return 10;
  if (n < P11) return 11;
  if (n < P12) return 12;
  if (n < P13) return 13;
  if (n < P14) return 14;
  if (n < P15) return 15;
  if (n < P16) return 16;
  if (n < P17) return 17;
  if (n < P18) return 18;
  if (n < P19) return 19;
  return 20;
}

uint32_t benchmark::digits10(uint32_t n) {
  if (n < P01) return 1;
  if (n < P02) return 2;
  if (n < P03) return 3;
  if (n < P04) return 4;
  if (n < P05) return 5;
  if (n < P06) return 6;
  if (n < P07) return 7;
  if (n < P08) return 8;
  if (n < P09) return 9;
  return 10;
}

uint32_t benchmark::digits10(uint16_t n) {
  if (n < P01) return 1;
  if (n < P02) return 2;
  if (n < P03) return 3;
  if (n < P04) return 4;
  return 5;
}

uint32_t benchmark::digits10(uint8_t n) {
  if (n < P01) return 1;
  if (n < P02) return 2;
  return 3;
}
