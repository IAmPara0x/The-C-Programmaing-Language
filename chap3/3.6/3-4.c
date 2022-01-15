#include <stdio.h>
#include <string.h>

/*
  Write a function expand(s1,s2) that expands shorthand notations like a-z in
  the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
  case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
  that a leading or trailing - is taken literally.
 */

void reverse(char *str1)
{
  int i, len, temp;
  len = strlen(str1);

  for (i = 0; i < len/2; i++)
  {
    temp = str1[i];
    str1[i] = str1[len - i - 1];
    str1[len - i - 1] = temp;
  }
}

void itoa(int n, char s[])
{
  int i, sign;
  unsigned int n_;
  if ((sign = n) < 0)
    n_ = -n;
  i = 0;
  do {
    s[i++] = n_ % 10 + '0'; /* get next digit */
  } while ((n_ /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main()
{
  char x = -128, s[10];
  itoa(x,s);
  printf("X: %s\n", s);
  return 0;
}
