#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
  int i,c,c1;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  c1 = getch();

  if (!isdigit(c) && c != '.' && !(c == '-' && isdigit(c1)))
    return c;
  else
    ungetch(c1);

  if (c == '-' && isdigit(c1))
  {
    i = 0;
    s[++i] = c;
    c = getch();
  }
  else
    i = 0;

  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}
