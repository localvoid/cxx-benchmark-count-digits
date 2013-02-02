#include <cstdint>
#include <iostream>
#include <string.h>
#include <sched.h>

#include "benchmark.hpp"

namespace {

template<typename T>
class Benchmark;

template<>
class Benchmark<uint64_t> {
public:
  static const uint64_t Numbers[20];
};

template<>
class Benchmark<uint32_t> {
public:
  static const uint32_t Numbers[10];
};

template<>
class Benchmark<uint16_t> {
public:
  static const uint16_t Numbers[5];
};

template<>
class Benchmark<uint8_t> {
public:
  static const uint8_t Numbers[3];
};

const uint64_t Benchmark<uint64_t>::Numbers[20] = {
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

const uint32_t Benchmark<uint32_t>::Numbers[10] = {
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

const uint16_t Benchmark<uint16_t>::Numbers[5] = {
  0,
  10,
  100,
  1000,
  10000
};

const uint8_t Benchmark<uint8_t>::Numbers[3] = {
  0,
  10,
  100
};


#if defined(__i386__)
uint64_t rdtsc() {
  uint64_t x;
  __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
  return x;
}
#elif defined(__x86_64__)
uint64_t rdtsc() {
  uint32_t hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ((uint64_t)lo)|(((uint64_t)hi)<<32 );
}
#endif

template<typename T>
uint64_t measure(T code) {
  uint64_t a = rdtsc();

  code();

  uint64_t b = rdtsc();

  return (b - a);
}

template<typename T>
void benchmark_digits10(int loop_count, int size) {
  int digits = 1;
  for (auto i: Benchmark<T>::Numbers) {
    uint64_t time = measure([i, loop_count]() {
        for (int x = 0; x < loop_count; ++x) {
          benchmark::digits10(i);
        }
      });

    std::cout << size << ',' << benchmark::name << ',' << digits << ',' << time/loop_count << std::endl;

    digits++;
  }
}

template<typename T>
void benchmark_digits10_2(int loop_count, int digits, int size) {
  auto i = Benchmark<T>::Numbers[digits-1];
  uint64_t time = measure([i, loop_count]() {
      for (int x = 0; x < loop_count; ++x) {
        benchmark::digits10(i);
      }
    });

  std::cout << size << ','  << benchmark::name << ',' << digits << ',' << time/loop_count << std::endl;

}


enum class BenchmarkMode {
  U64,
  U32,
  U16,
  U8
};

}

int main(int argc, char *argv[]) {
  cpu_set_t  mask;
  CPU_ZERO(&mask);
  CPU_SET(0, &mask);
  if (sched_setaffinity(0, sizeof(mask), &mask) < 0) {
    perror("sched_setaffinity");
  }


  int loop_count = 1;
  int digits = -1;
  BenchmarkMode mode = BenchmarkMode::U64;
  int size = 64;

  if (argc > 1) {
    loop_count = atoi(argv[1]);
    if (loop_count < 1) {
      std::cerr << "Invalid argument: loop counter" << std::endl;
      return 1;
    }

    if (argc > 2) {
      if (!strncmp("u8", argv[2], 2)) {
        mode = BenchmarkMode::U8;
      } else if (!strncmp("u16", argv[2], 3)) {
        mode = BenchmarkMode::U16;
      } else if (!strncmp("u32", argv[2], 3)) {
        mode = BenchmarkMode::U32;
      } else if (!strncmp("u64", argv[2], 3)) {
        mode = BenchmarkMode::U64;
      } else {
        std::cerr << "Invalid argument: unsupported mode" << std::endl;
        return 1;
      }

      if (argc > 3) {
        digits = atoi(argv[3]);

        int max_digits = 20;

        switch (mode) {
        case BenchmarkMode::U64:
          break;
        case BenchmarkMode::U32:
          max_digits = 10;
          size = 32;
          break;
        case BenchmarkMode::U16:
          max_digits = 5;
          size = 16;
          break;
        case BenchmarkMode::U8:
          max_digits = 3;
          size = 8;
          break;
        }

        if (digits < 1 || digits > max_digits) {
          std::cerr << "Invalid argument: digit count is out of range" << std::endl;
          return 1;
        }

      }
    }
  }

  switch (mode) {
  case BenchmarkMode::U64:
    break;
  case BenchmarkMode::U32:
    size = 32;
    break;
  case BenchmarkMode::U16:
    size = 16;
    break;
  case BenchmarkMode::U8:
    size = 8;
    break;
  }

  if (digits == -1) {
    switch (mode) {
    case BenchmarkMode::U64:
      benchmark_digits10<uint64_t>(loop_count, size);
      break;
    case BenchmarkMode::U32:
      benchmark_digits10<uint32_t>(loop_count, size);
      break;
    case BenchmarkMode::U16:
      benchmark_digits10<uint16_t>(loop_count, size);
      break;
    case BenchmarkMode::U8:
      benchmark_digits10<uint8_t>(loop_count, size);
      break;
    }
  } else {
    switch (mode) {
    case BenchmarkMode::U64:
      benchmark_digits10_2<uint64_t>(loop_count, digits, size);
      break;
    case BenchmarkMode::U32:
      benchmark_digits10_2<uint32_t>(loop_count, digits, size);
      break;
    case BenchmarkMode::U16:
      benchmark_digits10_2<uint16_t>(loop_count, digits, size);
      break;
    case BenchmarkMode::U8:
      benchmark_digits10_2<uint8_t>(loop_count, digits, size);
      break;
    }
  }


  return 0;
}
