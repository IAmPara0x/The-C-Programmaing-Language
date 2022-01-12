#include <stdio.h>
#include <string.h>

int main(){
  char s[6] = "Yuno\\0";
  printf("length of %s, %ld\n", s, strlen(s));
  return 0;
}
