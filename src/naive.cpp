#include <cstdint>

#include "benchmark.hpp"

const char *benchmark::name = "naive";

uint32_t benchmark::digits10(uint64_t v) {
  uint32_t result = 0;

  do {
    ++result;
    v /= 10;
  } while(v);

  return result;
}

uint32_t benchmark::digits10(uint32_t v) {
  uint32_t result = 0;

  do {
    ++result;
    v /= 10;
  } while(v);

  return result;
}

uint32_t benchmark::digits10(uint16_t v) {
  uint32_t result = 0;

  do {
    ++result;
    v /= 10;
  } while(v);

  return result;
}

uint32_t benchmark::digits10(uint8_t v) {
  uint32_t result = 0;

  do {
    ++result;
    v /= 10;
  } while(v);

  return result;
}
