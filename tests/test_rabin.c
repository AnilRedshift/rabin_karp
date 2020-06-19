#include "greatest.h"
#include "rabin.h"

TEST test_empty_substring()
{
  ASSERT(1);
  PASS();
}

SUITE(RabinSuite)
{
  RUN_TEST(test_empty_substring);
}

GREATEST_MAIN_DEFS();
int main(int argc, char *argv[])
{
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(RabinSuite);
  GREATEST_MAIN_END();
}
