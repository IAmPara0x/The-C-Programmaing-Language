#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
static int sp = 0;
static double val[MAXVAL];

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void print(void)
{
  double x = pop();
  printf("%lf\n", x);
  push(x);
}

void swap(void)
{
  if (sp < 1)
    printf("Error: Not enough values to swap.");

  double x1, x2;
  x1 = pop();
  x2 = pop();

  push(x1);
  push(x2);
}

void clear(void)
{
  sp = 0;
}

