#include <stdio.h>

/* Write a function reverse(s) that reverses the character string s. Use it to */
/* write a program that reverses its input a line at a time. */

void reverse(char line[]);

int main()
{
  char x[] = "onuy evol i";
  reverse(x);
  printf("%s\n", x);
  return 0;
}

void reverse(char line[])
{
  long line_length = 0;

  while (line[line_length] != '\0')
  {
    ++line_length;
  }

  if (line_length != 0)
  {
    for (int i = 0; i < line_length/2; ++i)
    {
      long lastidx = line_length - 1 - i;
      char x = line[i];
      line[i] = line[lastidx];
      line[lastidx] = x;
    }
  }

}
