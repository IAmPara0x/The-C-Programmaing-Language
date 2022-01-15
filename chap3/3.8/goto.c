#include <stdio.h>

int main()
{
  int x = 10;
yuno:
  printf("Yuno\n");

  for (int i = 0; i < x; ++i)
  {
    --x;
    goto yuno;
  }
  return 0;
}
