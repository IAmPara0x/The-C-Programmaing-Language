#include <stdio.h>

/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
 s1 that matches any character in the string s2. */

void squeeze(char s[], int c)
{
  int i,j;
  for(i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

void squeeze2(char s1[], char s2[])
{
  for (int i = 0; s2[i] != '\0'; ++i)
    squeeze(s1,s2[i]);
}

int main()
{
  char s1[] = "Yuno Gasai";
  char s2[] = "aGasi ";
  printf("Str: %s\n", s1);
  squeeze2(s1,s2);
  printf("Changed Str: %s\n", s1);

}
