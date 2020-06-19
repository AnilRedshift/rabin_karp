#include "rabin.h"
#include "primes.h"
#include <string.h>

#define RADIX 128

typedef struct
{
  size_t hash;
  char leading_char;
  size_t most_significant_digit_weight;
  int prime;
} HASH_DATA;

static bool are_equal(char const *a, char const *b, size_t len)
{
  for (size_t i = 0; i < len; ++i)
  {
    if (a[i] != b[i] || a[i] == '\0' || b[i] == '\0')
    {
      return false;
    }
  }
  return true;
}

static HASH_DATA hash(char const *s, size_t len, int prime)
{
  HASH_DATA data = {.hash = 0, .leading_char = s[0], .prime = prime, .most_significant_digit_weight = 1};
  for (size_t i = 0; i < len; ++i)
  {
    data.hash = ((RADIX * data.hash) + s[i]) % prime;
  }

  for (size_t i = 1; i < len; ++i)
  {
    data.most_significant_digit_weight = (data.most_significant_digit_weight * RADIX) % prime;
  }
  return data;
}

static void remove_leading_char_from_hash(HASH_DATA *hash, const char next_char)
{
  size_t to_remove = hash->leading_char * hash->most_significant_digit_weight;
  // We add an extra prime to the value before subtractingto ensure the number is non-negative
  // since size_t is unsigned. Since we mod prime afterwards, this is a no-op
  hash->hash = ((hash->hash + hash->prime) - to_remove) % hash->prime;
  hash->leading_char = next_char;
}

static void roll_hash(HASH_DATA *hash, const char next_char, const char last_char)
{
  remove_leading_char_from_hash(hash, next_char);
  hash->hash = (hash->hash * RADIX) % hash->prime;     // Shift left by a digit
  hash->hash = (hash->hash + last_char) % hash->prime; // Add the new value
}

bool is_substring(char const *text, char const *pattern, size_t *output_match_index)
{
  bool found_match = false;
  size_t match_index;

  if (text != NULL && pattern != NULL)
  {
    size_t pattern_len = strlen(pattern);
    size_t text_len = strlen(text);

    if (pattern_len == 0 || (text_len >= pattern_len && memcmp(text, pattern, pattern_len) == 0))
    {
      found_match = true;
      match_index = 0;
    }
    else if (text_len >= pattern_len)
    {
      const int prime = get_prime();
      const HASH_DATA target_hash = hash(pattern, pattern_len, prime);
      HASH_DATA current_hash = hash(text, pattern_len, prime);
      for (size_t i = pattern_len; i < text_len; ++i)
      {
        const size_t next_index = 1 + (i - pattern_len);
        const char next_char = text[next_index];
        const char last_char = text[i];
        roll_hash(&current_hash, next_char, last_char);
        if (current_hash.hash == target_hash.hash && are_equal(&text[next_index], pattern, pattern_len))
        {
          found_match = true;
          match_index = next_index;
          break;
        }
      }
    }
  }

  if (found_match && output_match_index != NULL)
  {
    *output_match_index = match_index;
  }
  return found_match;
}
