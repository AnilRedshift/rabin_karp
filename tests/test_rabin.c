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

TEST test_pattern_too_large()
{
  bool actual = is_substring("abc", "abcd", NULL);
  ASSERT_FALSE(actual);

  actual = is_substring("abc", "abc", NULL);
  ASSERT(actual);
  PASS();
}

TEST test_match_at_beginning()
{
  size_t index;
  bool actual = is_substring("abc", "a", &index);
  ASSERT(actual);
  ASSERT_EQ_FMT((size_t)0, index, "%zu");

  actual = is_substring("abc", "abc", &index);
  ASSERT(actual);
  ASSERT_EQ_FMT((size_t)0, index, "%zu");
  PASS();
}

TEST test_one_char_pattern()
{
  size_t index;
  bool actual = is_substring("abc", "b", &index);
  ASSERT(actual);
  ASSERT_EQ_FMT((size_t)1, index, "%zu");
  PASS();
}

TEST test_two_char_pattern()
{
  size_t index;
  bool actual = is_substring("abcdefg", "de", &index);
  ASSERT(actual);
  ASSERT_EQ_FMT((size_t)3, index, "%zu");
  PASS();
}

TEST test_match_at_end()
{
  size_t index;
  bool actual = is_substring("abcdefg", "fg", &index);
  ASSERT(actual);
  ASSERT_EQ_FMT((size_t)5, index, "%zu");
  PASS();
}

TEST test_no_match()
{
  size_t index;
  bool actual = is_substring("abcdefg", "cdde", &index);
  ASSERT_FALSE(actual);
  PASS();
}

SUITE(RabinSuite)
{
  RUN_TEST(test_empty);
  RUN_TEST(test_null);
  RUN_TEST(test_pattern_too_large);
  RUN_TEST(test_match_at_beginning);
  RUN_TEST(test_one_char_pattern);
  RUN_TEST(test_two_char_pattern);
  RUN_TEST(test_match_at_end);
}

GREATEST_MAIN_DEFS();
int main(int argc, char *argv[])
{
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(RabinSuite);
  GREATEST_MAIN_END();
}
