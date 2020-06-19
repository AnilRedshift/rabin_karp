#include <stdio.h>
#include "rabin.h"

int main()
{
  const char text[] = "myaoeuy";
  const char pattern[] = "aoeu";
  size_t match = get_index_of_substring(text, pattern);
  printf("hello world match index is %zu\n", match);
  return 0;
}
