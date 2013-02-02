#ifndef _BENCHMARK_HPP_
#define _BENCHMARK_HPP_

#include <cstdint>

namespace benchmark {

uint32_t digits10(uint64_t v);
uint32_t digits10(uint32_t v);
uint32_t digits10(uint16_t v);
uint32_t digits10(uint8_t v);

extern const char *name;

}

#endif
