#include <cstdint>
#include "benchmark.hpp"

const char *benchmark::name = "bth-bsr";

static const uint64_t powers_of_10[] = {
  0,
  10,
  100,
  1000,
  10000,
  100000,
  1000000,
  10000000,
  100000000,
  1000000000,
  10000000000,
  100000000000,
  1000000000000,
  10000000000000,
  100000000000000,
  1000000000000000,
  10000000000000000,
  100000000000000000,
  1000000000000000000,
  10000000000000000000U
};

static const uint32_t powers_of_10_u32[] = {
  0,
  10,
  100,
  1000,
  10000,
  100000,
  1000000,
  10000000,
  100000000,
  1000000000
};


static inline unsigned long bsrq(unsigned long mask) {
  unsigned long result;
  asm volatile("bsrq %1,%0" : "=r" (result) : "rm" (mask));
  return result;
}

static inline unsigned int bsrl(unsigned int mask) {
  unsigned int result;
  asm volatile("bsrl %1,%0" : "=r" (result) : "rm" (mask));
  return result;
}

static inline unsigned short bsrw(unsigned short mask) {
  unsigned short result;
  asm volatile("bsrw %1,%0" : "=r" (result) : "rm" (mask));
  return result;
}


uint32_t benchmark::digits10(std::uint64_t n) {
  uint32_t t = (bsrq(n | 1) + 1) * 1233 >> 12;
  return t - (n < powers_of_10[t]) + 1;
}

uint32_t benchmark::digits10(uint32_t n) {
  uint32_t t = (bsrq(n | 1) + 1) * 1233 >> 12;
  return t - (n < powers_of_10_u32[t]) + 1;
}

uint32_t benchmark::digits10(uint16_t v) {
  uint32_t n = v;
  uint32_t t = (bsrq(n | 1) + 1) * 1233 >> 12;
  return t - (n < powers_of_10_u32[t]) + 1;
}

uint32_t benchmark::digits10(uint8_t v) {
  uint32_t n = v;
  uint32_t t = (bsrq(n | 1) + 1) * 1233 >> 12;
  return t - (n < powers_of_10_u32[t]) + 1;
}
