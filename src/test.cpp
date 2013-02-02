#include <cstdint>
#include <random>
#include <iostream>
#include "benchmark.hpp"

namespace {

uint32_t valid_digits_10(uint64_t v) {
  uint32_t result = 0;

  do {
    ++result;
    v /= 10;
  } while(v);

  return result;
}


const uint64_t numbers_64[] = {
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
  10000000000000000000U,
  UINT64_MAX
};

const uint32_t numbers_32[] = {
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
  UINT32_MAX
};

const uint16_t numbers_16[] = {
  0,
  10,
  100,
  1000,
  10000,
  UINT16_MAX
};

const uint8_t numbers_8[] = {
  0,
  10,
  100,
  UINT8_MAX
};

template<typename T>
void check(T v) {
  if (valid_digits_10(v) != benchmark::digits10(v)) {
    std::cout << "FAIL: " << static_cast<uint64_t>(v) << std::endl;
  }
}

void simple_test() {
  std::cout << "simple test" << std::endl;

  std::cout << "Checking 64bit" << std::endl;
  for (auto i: numbers_64)
    check(i);
  std::cout << "Checking 32bit" << std::endl;
  for (auto i: numbers_32)
    check(i);
  std::cout << "Checking 16bit" << std::endl;
  for (auto i: numbers_16)
    check(i);
  std::cout << "Checking 8bit" << std::endl;
  for (auto i: numbers_8)
    check(i);
}


void random_test() {
  std::cout << "random test" << std::endl;

  std::mt19937 rng;
  std::uniform_int_distribution<uint64_t> uint64_dist;

  rng.seed(31337);
  for (;;) {
    uint64_t v = uint64_dist(rng);
    if (valid_digits_10(v) != benchmark::digits10(v)) {
      std::cout << "FAIL: " << v << std::endl;
    }
  }
}

}

int main(int argc, char *argv[]) {
  uint32_t ret = 0;

  std::cout << benchmark::name << std::endl;

  if (argc == 1)
    simple_test();
  else
    random_test();


  return ret;
}
