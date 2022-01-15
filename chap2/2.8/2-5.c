#include <stdio.h>

/*
  Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
  where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
  (The standard library function strpbrk does the same job but returns a pointer to the
  location.)
 */

int any (const char s1[], const char s2[])
{
  char c1,c2;
  int i,j;
  for (i = 0; (c2 = s2[i]) != '\0'; ++i)
    for (j = 0; (c1 = s1[j]) != '\0'; ++j)
      if (c1 == c2)
        return j;
  return -1;
}

int main()
{
  char s1[] = "Yuno";
  char s2[] = "Gasai";
  printf("Loc: %d\n", any(s1,s2));

  return 0;
}
