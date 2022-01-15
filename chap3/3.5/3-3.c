#include <stdio.h>
#include <string.h>

/*
  Write a function expand(s1,s2) that expands shorthand notations like a-z in
  the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
  case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
  that a leading or trailing - is taken literally.
 */

void expand (char s1[], char s2[])
{

  int n, idx2, idx1, u_bound, l_bound;
  char l_char, u_char;

  n = strlen(s1);
  idx1 = idx2 = 0;

  while (idx1 < n)
    if (s1[idx1] == '-')
    {
      l_bound = s1[idx1-1];

      for(int i = idx1; s1[i] == '-' && i < n; i += 2)
      {
        idx1 = i+1;
        u_bound = s1[idx1];
      }

      for (l_char = l_bound, u_char = u_bound; l_char <= u_char; l_char++)
        s2[idx2++] = l_char;
    }
    else
      idx1++;

  s2[idx2] = '\0';
}


int main()
{
  char s1[] = "a-b-c-d-e-f0-1-5A-D";
  char s2[100];
  expand(s1,s2);
  printf("S2: %s\n", s2);
  return 0;
}

