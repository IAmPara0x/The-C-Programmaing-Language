#include <stdio.h>

/* Write a program detab that replaces tabs in the input with the proper number */
/* of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. */
/* Should n be a variable or a symbolic parameter? */

#define TABLENGTH 2
#define MAXLINE 1024

void detab(char string[], char empty_string[], int tablength);

int main(){
  char input[] = "i\tlove\tyuno", empty_string[MAXLINE];
  printf("%s\n",input);
  detab(input,empty_string,TABLENGTH);
  printf("%s", empty_string);
  return 0;
}

void detab(char string[], char empty_string[], int tablength)
{
  int new_string_idx = 0;
  char c;

  for (int i = 0; (c = string[i]) != '\0'; ++i)
    if (c == '\t')
      for (int _ = 0; _ < tablength; ++_)
      {
        empty_string[new_string_idx] = ' ';
        ++new_string_idx;
      }
    else
    {
      empty_string[new_string_idx] = c;
      ++new_string_idx;
    }

  empty_string[new_string_idx] = '\0';
}
