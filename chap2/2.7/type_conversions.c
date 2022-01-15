#include <stdio.h>

int atoi (char s[])
{
  int i,n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
  {
    printf("%c -> %d\n", s[i], s[i] - '0');
    n = 10*n + (s[i] - '0');
  }
  return n;
}

int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

void test_fn(long x)
{
  printf("size of `x` in `test_fn` is %ld\n", sizeof(x));
};

void ascii_code(int c)
{
  printf("Ascii code: %c -> %d\n", c, c);
}

int main(){

  char s[6] = "123";
  printf("%d\n", atoi(s));
  ascii_code('A');
  ascii_code('Z');
  ascii_code('a');


  // Automatic Type conversions in comparision operators
  printf("bool: %d\n", -1L < 1UL);


  // Automatic Type conversions in function args
  short x;
  printf("size of `x` is: %ld\n", sizeof(x));
  test_fn(x);

  return 0;
}
