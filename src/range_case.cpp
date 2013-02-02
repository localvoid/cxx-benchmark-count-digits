#include <cstdint>
#include "benchmark.hpp"

const char *benchmark::name = "range_case";

uint32_t benchmark::digits10(uint64_t v) {
  switch (v) {
  case                   0ULL ...                   9ULL : return  1 ;
  case                  10ULL ...                  99ULL : return  2 ;
  case                 100ULL ...                 999ULL : return  3 ;
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
  switch (v) {
  case         0UL ...         9UL : return  1 ;
  case        10UL ...        99UL : return  2 ;
  case       100UL ...       999UL : return  3 ;
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
  switch (v) {
  case    0U ...    9U : return 1 ;
  case   10U ...   99U : return 2 ;
  case  100U ...  999U : return 3 ;
  case 1000U ... 9999U : return 4 ;
  default              : return 5 ;
  };
};

uint32_t benchmark::digits10(uint8_t v) {
  switch (v) {
  case  0U ...  9U : return 1 ;
  case 10U ... 99U : return 2 ;
  default          : return 3 ;
  };
};
