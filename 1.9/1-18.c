#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Write a program to remove trailing blanks and tabs from each line of input, */
/* and to delete entirely blank lines. */
// NOTE: using extra library for bool and getchar will not terminate that's why i am manually giving input.

#define MAXLINE 1000
#define TRAIL_CHARS {'\t', ' ', '\n'}

void remove_trail_chars(char line[]);

int main(){
  char input[] = "i love yuno    \n\n";
  char line[MAXLINE];


  printf("%ld\n", strlen(input));
  remove_trail_chars(input);
  printf("%s", input);
  printf("%ld\n", strlen(input));

  return 0;
}

void remove_trail_chars(char line[]){
  long line_length = strlen(line);
  char trail_chars[] = TRAIL_CHARS;
  bool is_trailing = false;

  if (line[line_length - 1] == '\n')
    for(int i = line_length - 2; i >= 0; --i)
    {

      for (int j = 0; j < strlen(trail_chars); ++j)
        if (trail_chars[j] == line[i])
        {
          is_trailing = true;
          line[i] = '\n';
          line[i+1] = '\0';
        }

      if (is_trailing == false)
        break;
      is_trailing = false;
    }
}

