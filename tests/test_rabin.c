#include "greatest.h"
#include "rabin.h"

TEST test_empty()
{
  bool actual = is_substring("aoeu", "", NULL);
  ASSERT(actual);

  actual = is_substring("", "", NULL);
  ASSERT(actual);

  actual = is_substring("", "aoeu", NULL);
  ASSERT_FALSE(actual);
  PASS();
}

TEST test_null()
{
  bool actual = is_substring(NULL, "aeou", NULL);
  ASSERT_FALSE(actual);

  actual = is_substring(NULL, "", NULL);
  ASSERT_FALSE(actual);

  actual = is_substring("aoeu", NULL, NULL);
  ASSERT_FALSE(actual);

  actual = is_substring("", NULL, NULL);
  ASSERT_FALSE(actual);

  actual = is_substring(NULL, NULL, NULL);
  ASSERT_FALSE(actual);
  PASS();
}

SUITE(RabinSuite)
{
  RUN_TEST(test_empty);
  RUN_TEST(test_null);
}

GREATEST_MAIN_DEFS();
int main(int argc, char *argv[])
{
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(RabinSuite);
  GREATEST_MAIN_END();
}
