#include "primes.h"
#include "primes_data.h"
#include <stdlib.h>

#define NUM_PRIMES (sizeof(primes) / sizeof(primes[0]))

int get_prime()
{
  size_t index = rand() % NUM_PRIMES;
  return primes[index];
}
