#include <stdio.h>

/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
*/

unsigned long power(int x,  unsigned short n)
{
  unsigned long value = 1;
  while(n != 0)
  {
    value *= x;
    --n;
  };
  return value;
}


void char_range()
{
  unsigned char us_char = 1, us_char_ = 0;
  while ((us_char-1) == us_char_)
  {
    ++us_char, ++us_char_;
  };
  printf("range of unsigned char: (%d, %d)\n", us_char, us_char_);

  signed char s_char = 1, s_char_ = 0;
  while ((s_char-1) == s_char_)
  {
    ++s_char, ++s_char_;
  };
  printf("range of unsigned char: (%d, %d)\n", s_char, s_char_);
}

void short_range()
{
  unsigned short us_short = 1, us_short_ = 0;

  while ((us_short - 1) == us_short_)
  {
    ++us_short, ++us_short_;
  };
  printf("range of unsigned short: (%d, %d)\n", us_short, us_short_);

  signed short s_short = 1, s_short_ = 0;

  while ((s_short - 1) == s_short_)
  {
    ++s_short, ++s_short_;
  };
  printf("range of signed short: (%d, %d)\n", s_short, s_short_);
}

void int_range()
{
  unsigned int n_bits;
  n_bits = 8*sizeof(n_bits);
  unsigned long value = power(2,n_bits), halve = value / 2;
  printf("range of unsigned long (0, %ld)\n", value);
  printf("range of signed long (-%ld, %ld)\n", halve,halve-1);
  printf("decimal: %.3f\n", 1234e-1);

  char x[4] = "yuno";
  for (int i = 0; i < 4; ++i)
    printf("%c -> %d\n", x[i], x[i]);
  printf("tab in octa: %d\n", '\131');
}

int main()
{
  char_range();
  short_range();
  int_range();
  return 0;
}
