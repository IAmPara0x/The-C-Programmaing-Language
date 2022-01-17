#include <stdio.h>

#define PRINT_INT(a) printf("The value of yuno is : %d\n", a)
#define PASTE(x, y) x ## y


int main()
{
  int yuno = 10;
  PRINT_INT(PASTE(yun, o));
  return 0;
}
