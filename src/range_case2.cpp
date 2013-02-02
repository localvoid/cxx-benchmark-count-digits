#include <cstdint>
#include "benchmark.hpp"

const char *benchmark::name = "range_case2";

uint32_t benchmark::digits10(uint64_t v) {
  if (v < 10)   return 1;
  if (v < 100)  return 2;
  if (v < 1000) return 3;
  switch (v) {
  case                1000ULL ...                9999ULL : return  4 ;
  case               10000ULL ...               99999ULL : return  5 ;
  case              100000ULL ...              999999ULL : return  6 ;
  case             1000000ULL ...             9999999ULL : return  7 ;
  case            10000000ULL ...            99999999ULL : return  8 ;
  case           100000000ULL ...           999999999ULL : return  9 ;
  case          1000000000ULL ...          9999999999ULL : return 10 ;
  case         10000000000ULL ...         99999999999ULL : return 11 ;
  case        100000000000ULL ...        999999999999ULL : return 12 ;
  case       1000000000000ULL ...       9999999999999ULL : return 13 ;
  case      10000000000000ULL ...      99999999999999ULL : return 14 ;
  case     100000000000000ULL ...     999999999999999ULL : return 15 ;
  case    1000000000000000ULL ...    9999999999999999ULL : return 16 ;
  case   10000000000000000ULL ...   99999999999999999ULL : return 17 ;
  case  100000000000000000ULL ...  999999999999999999ULL : return 18 ;
  case 1000000000000000000ULL ... 9999999999999999999ULL : return 19 ;
  default                                                : return 20 ;
  };
};

uint32_t benchmark::digits10(uint32_t v) {
  if (v < 10)   return 1;
  if (v < 100)  return 2;
  if (v < 1000) return 3;
  switch (v) {
  case      1000UL ...      9999UL : return  4 ;
  case     10000UL ...     99999UL : return  5 ;
  case    100000UL ...    999999UL : return  6 ;
  case   1000000UL ...   9999999UL : return  7 ;
  case  10000000UL ...  99999999UL : return  8 ;
  case 100000000UL ... 999999999UL : return  9 ;
  default                          : return 10 ;
  };
};

uint32_t benchmark::digits10(uint16_t v) {
  if (v < 10)   return 1;
  if (v < 100)  return 2;
  if (v < 1000) return 3;
  switch (v) {
  case 1000U ... 9999U : return 4 ;
  default              : return 5 ;
  };
};

uint32_t benchmark::digits10(uint8_t v) {
  if (v < 10)   return 1;
  if (v < 100)  return 2;
  return 3;
};
