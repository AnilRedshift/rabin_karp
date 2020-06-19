#include "greatest.h"
#include "primes.h"
#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n)
{
  if (n <= 1)
  {
    return false;
  }

  for (int i = 2; i < n; i++)
    if (n % i == 0)
    {
      return false;
    }

  return true;
}

TEST test_prime()
{
  const int prime = get_prime();
  const bool actual = is_prime(prime);
  char msg[50];
  sprintf(msg, "Value %d is not prime", prime);
  ASSERT_EQ_FMTm(msg, true, actual, "%c");
  PASS();
}

SUITE(PrimesSuite)
{
  RUN_TEST(test_prime);
}

GREATEST_MAIN_DEFS();
int main(int argc, char *argv[])
{
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(PrimesSuite);
  GREATEST_MAIN_END();
}
