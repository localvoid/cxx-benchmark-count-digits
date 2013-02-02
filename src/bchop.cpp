#include <cstdint>
#include "benchmark.hpp"

const char *benchmark::name = "bchop";

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
  uint32_t r = 1;
  if (n >= P16) {
    r += 16;
    n /= P16;
  }
  if (n >= P08) {
    r += 8;
    n /= P08;
  }
  if (n >= P04) {
    r += 4;
    n /= P04;
  }
  if (n >= P02) {
    r += 2;
    n /= P02;
  }
  if (n >= P01)
    r++;

  return r;
}

uint32_t benchmark::digits10(uint32_t n) {
  uint32_t r = 1;
  if (n >= P08) {
    r += 8;
    n /= P08;
  }
  if (n >= P04) {
    r += 4;
    n /= P04;
  }
  if (n >= P02) {
    r += 2;
    n /= P02;
  }
  if (n >= P01)
    r++;

  return r;
}

uint32_t benchmark::digits10(uint16_t n) {
  uint32_t r = 1;
  if (n >= P04) {
    r += 4;
    n /= P04;
  }
  if (n >= P02) {
    r += 2;
    n /= P02;
  }
  if (n >= P01)
    r++;

  return r;
}

uint32_t benchmark::digits10(uint8_t n) {
  uint32_t r = 1;
  if (n >= P02) {
    r += 2;
    n /= P02;
  }
  if (n >= P01)
    r++;

  return r;
}
