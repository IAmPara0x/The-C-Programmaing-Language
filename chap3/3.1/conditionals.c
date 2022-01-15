#include <stdio.h>

int binsearch(int x, int v[], int n)
{
  int low, high, mid, x_;

  low = 0, high = n-1;

  while (low <= high)
  {
    mid = (low + high) / 2;
    x_ = v[mid];
    if (x < x_)
      high = mid + 1;
    else
      low = mid + 1;
  }
  if (x_ == x)
    return mid;
  else
    return -1;
}

int main()
{
  printf("yuno\n");
  return 0;
}
