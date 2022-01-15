#include <stdio.h>

void showbits( unsigned char x )
{
    int i=0;
    for (i = (sizeof(char) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

int main()
{
  unsigned char x = 6;

  showbits(x);
  printf("Number: %d\n", x);


  showbits(~x);
  printf("Number: %d\n", (~x));

  return 0;
}
