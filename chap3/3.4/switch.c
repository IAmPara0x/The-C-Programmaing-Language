#include <stdio.h>

void escape(char s[], char t[])
{
  char c;
  int i,j;
  i = j = 0;
  for (i=0; (c=s[i]) != '\0'; ++i)
    switch(c)
    {
      case '\t':
        t[j++] = '\\';
        t[j++] = 't';
        break;

      case '\n':
        t[j++] = '\\';
        t[j++] = 'n';
        break;

      case '\b':
        t[j++] = '\\';
        t[j++] = 'b';
        break;

      default:
        t[j++] = c;
        break;
    }
  t[j] = '\0';
}

int main()
{
  char s[10] = "Yuno\n\t\0",t[10];
  escape(s,t);
  printf("Escaped str: %s\n", t);
  return 0;
}
