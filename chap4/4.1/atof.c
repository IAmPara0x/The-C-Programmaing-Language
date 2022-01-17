#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i++] == 'e' || s[i++] == 'E')
  {
    short p;
    int power_sign;

    if (s[i] == '-')
      power_sign = -1, i++;
    else
      power_sign = 1;

    if (isdigit(s[i]))
    {
      p = s[i] - '0';

      if (power_sign == 1)
        for(p = p; p > 0; --p)
          power /= 10;
      else
        for(p = p; p > 0; --p)
          power *= 10;
    }
  }

  return sign * val / power;
}

int main()
{
  char s[] = "13.22e3";
  printf("atof: %s -> %lf\n", s, atof(s));
  return 0;
}

