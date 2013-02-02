#include <cstdint>
#include "benchmark.hpp"

const char *benchmark::name = "bsearch";

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


uint32_t benchmark::digits10(uint64_t v) {
  if (v < P01) return 1;
  if (v < P02) return 2;
  if (v < P03) return 3;
  if (v < P12) {
    if (v < P08) {
      if (v < P06) {
        if (v < P04) return 4;
        return 5 + (v >= P05);
      }
      return 7 + (v >= P07);
    }
    if (v < P10) {
      return 9 + (v >= P09);
    }
    return 11 + (v >= P11);
  }
  return 12 + digits10(v / P12);
}

uint32_t benchmark::digits10(uint32_t v) {
  if (v < P01) return 1;
  if (v < P02) return 2;
  if (v < P03) return 3;
  if (v < P08) {
    if (v < P06) {
      if (v < P04) return 4;
      return 5 + (v >= P05);
    }
    return 7 + (v >= P07);
  }
  if (v < P10) {
    return 9 + (v >= P09);
  }
  return 11;
}

uint32_t benchmark::digits10(uint16_t v) {
  if (v < P01) return 1;
  if (v < P02) return 2;
  if (v < P03) return 3;
  if (v < P04) return 4;
  return 5;
}

uint32_t benchmark::digits10(uint8_t v) {
  if (v < P01) return 1;
  if (v < P02) return 2;
  return 3;
}
