#include <stdio.h>
#include "rabin.h"

int main()
{
  const char text[] = "myaoeuy";
  const char pattern[] = "aoeu";
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
  return 0;
}
