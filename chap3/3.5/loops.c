#include <stdio.h>
#include <ctype.h>

int atoi(char s[])
{

  int i, n, sign;

  for (i=0; isspace(s[i]); ++i)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');

  return sign * n;
}

void shellshort(int v[], int n)
{
  int gap, i, j, temp;
  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j=i-gap; j >= 0 && v[j]>v[j+gap]; j-=gap)
      {
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
      }
}

int main()
{
  char x[] = "   -1234a";
  printf("atoi: %s -> %d\n", x, atoi(x));
  printf("Yuno\n");
  return 0;
}
