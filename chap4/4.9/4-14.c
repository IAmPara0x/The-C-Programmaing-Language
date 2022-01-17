
#include <stdio.h>

/*
Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.)
*/

#define swap(t,x,y) t temp = x; x = y; y = temp;

int main()
{
  char y = 'Y', u = 'U';
  printf("(y,u): (%c,%c)\n", y,u);

  swap(int, y, u);

  printf("(y,u): (%c,%c)\n", y,u);

  return 0;
}
