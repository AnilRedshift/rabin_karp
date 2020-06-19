#include <stdio.h>
#include "rabin.h"

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Syntax: rabin text pattern\n");
    return -1;
  }

  const char *text = argv[1];
  const char *pattern = argv[2];
  size_t match_index;
  bool has_match = is_substring(text, pattern, &match_index);
  if (has_match)
  {
    printf("Match found at %zu\n", match_index);
  }
  else
  {
    printf("No match \n");
  }
  return has_match ? 0 : -1;
}
