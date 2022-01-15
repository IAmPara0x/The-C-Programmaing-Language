#include <stdio.h>
#include <string.h>

/*
Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#define MAX_WORD_LENGTH 16
#define WORD_DELIMITER_LENGTH 4
#define IN 0
#define OUT 1

int main(){

  char WORD_DELIMITERS[WORD_DELIMITER_LENGTH] = {'\n', ' ', '\t', '\0'};
  char *input = "i love yuno";

  int word_length, c, is_delimit;
  int word_length_arr[MAX_WORD_LENGTH];

  // initialization
  for (int i = 0; i < MAX_WORD_LENGTH; ++i)
    word_length_arr[i] = 0;
  word_length = 0;


  for (int j = 0; j < strlen(input) + 1; ++j){
    c = input[j];

    is_delimit = IN;
    for (int i = 0; i < WORD_DELIMITER_LENGTH; ++i)
      if (c == WORD_DELIMITERS[i])
        is_delimit = OUT;

    if (is_delimit == OUT){
      if (word_length != 0 && word_length < MAX_WORD_LENGTH)
        word_length_arr[word_length] = word_length_arr[word_length] + 1;
      word_length = 0;
    }else
      ++word_length;
  }
  printf("WORD LENGTHS\n");

  for (int index = 1; index < MAX_WORD_LENGTH; ++index){
    printf("%d:\t\b\b", index);
    for(int count = word_length_arr[index]; count > 0; --count){
      printf("#");
    }
    printf("\n\n");
  }

}
