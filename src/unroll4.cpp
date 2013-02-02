#include <cstdint>
#include "benchmark.hpp"

const char *benchmark::name = "unroll4";

uint32_t benchmark::digits10(uint64_t v) {
  uint32_t result = 1;
  for (;;) {
    if (v < 10)    return result;
    if (v < 100)   return result + 1;
    if (v < 1000)  return result + 2;
    if (v < 10000) return result + 3;
    v /= 10000ULL;
    result += 4;
  }
}

uint32_t benchmark::digits10(uint32_t v) {
  uint32_t result = 1;
  for (;;) {
    if (v < 10)    return result;
    if (v < 100)   return result + 1;
    if (v < 1000)  return result + 2;
    if (v < 10000) return result + 3;
    v /= 10000ULL;
    result += 4;
  }
}

uint32_t benchmark::digits10(uint16_t v) {
  uint32_t result = 1;
  for (;;) {
    if (v < 10)    return result;
    if (v < 100)   return result + 1;
    if (v < 1000)  return result + 2;
    if (v < 10000) return result + 3;
    v /= 10000ULL;
    result += 4;
  }
}

uint32_t benchmark::digits10(uint8_t v) {
  uint32_t result = 1;
  for (;;) {
    if (v < 10)    return result;
    if (v < 100)   return result + 1;
    if (v < 1000)  return result + 2;
    if (v < 10000) return result + 3;
    v /= 10000ULL;
    result += 4;
  }
}
