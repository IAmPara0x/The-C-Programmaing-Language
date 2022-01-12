#include <stdio.h>


int strlen(const char str[])
{
  unsigned long i;
  while (str[i] != '\0')
    ++i;
  return i;
};

 /*

Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

 for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
   s[i] = c;


int i = 0;

while (i < lim-1)
{
  if ((c=getchar()) != '\n')
    if (c != EOF)
    {
      s[i] = c;
      ++i;
    }
}

**/


int main(){
  int x;
  printf("%d\n", x);
  return 0;
}
