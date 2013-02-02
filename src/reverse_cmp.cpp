#include <cstdint>
#include "benchmark.hpp"

const char *benchmark::name = "reverse_cmp";

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
  return 1 + ((v >= P19) ? 19 : (v >= P18) ? 18 : (v >= P17) ? 17 :
              (v >= P16) ? 16 : (v >= P15) ? 15 : (v >= P14) ? 14 :
              (v >= P13) ? 13 : (v >= P12) ? 12 : (v >= P11) ? 11 :
              (v >= P10) ? 10 : (v >= P09) ?  9 : (v >= P08) ?  8 :
              (v >= P07) ?  7 : (v >= P06) ?  6 : (v >= P05) ?  5 :
              (v >= P04) ?  4 : (v >= P03) ?  3 : (v >= P02) ?  2 :
              (v >= P01) ?  1 : 0);
}

uint32_t benchmark::digits10(uint32_t v) {
  return 1 + ((v >= P10) ? 10 : (v >= P09) ?  9 : (v >= P08) ?  8 :
              (v >= P07) ?  7 : (v >= P06) ?  6 : (v >= P05) ?  5 :
              (v >= P04) ?  4 : (v >= P03) ?  3 : (v >= P02) ?  2 :
              (v >= P01) ?  1 : 0);
}

uint32_t benchmark::digits10(uint16_t v) {
  return 1 + ((v >= P04) ?  4 : (v >= P03) ?  3 :
              (v >= P02) ?  2 : (v >= P01) ?  1 : 0);
}

uint32_t benchmark::digits10(uint8_t v) {
  return 1 + ((v >= P02) ?  2 : (v >= P01) ?  1 : 0);
}
