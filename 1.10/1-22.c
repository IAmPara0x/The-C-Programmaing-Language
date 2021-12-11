#include <stdio.h>
#include <stdlib.h>

// Write a program to ``fold'' long input lines into two or more shorter lines after
// the last non-blank character that occurs before the n-th column of input. Make sure your
// program does something intelligent with very long lines, and if there are no blanks or tabs
// before the specified column.

#define FOLD_LENGTH 40
#define FOLD_CHARS {' ', '\t'}
#define FOLD_CHARS_LENGTH 2

#define MAX_LENGTH 1024

void fold_line(char line[], int fold_length);

int main()
{

  // Stuff reading file.
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("1.10/1-22.c", "r");
  if (fp == NULL)
      exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1) {
      fold_line(line, FOLD_LENGTH); // folding line
      printf("%s", line);
  }

  fclose(fp);
  if (line)
      free(line);
  exit(EXIT_SUCCESS);
  return 0;
}

void fold_line(char line[], int fold_length)
{
  //NOTE: Assumes the input is a single line.
  //TODO: Add some kind of tolerenace of characters.
  if (fold_length > 0)
  {
    int line_length = 0, prev_break_idx = -1;
    char c=line[0], fold_chars[] = FOLD_CHARS;

    for (int i = 0; (c = line[i]) != '\0'; ++i)
    {

      for (int char_idx = 0; char_idx < FOLD_CHARS_LENGTH; ++char_idx)
        if (fold_chars[char_idx] == c)
        {
          prev_break_idx = i;
        }

      ++line_length;

      if (line_length > fold_length && prev_break_idx != -1)
      {
        line[prev_break_idx] = '\n';
        line_length = line_length - fold_length;
        prev_break_idx = -1;
      }
    }
  }
}
