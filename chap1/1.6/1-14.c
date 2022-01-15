#include <stdio.h>
#include <string.h>

/*
Write a program to print a histogram of the frequencies of different characters
in its input.
*/

#define MAX_ASCII_VALUE 128

int main(){

  int char_frequency[128], c;
  char *input = "i love yuno";

  // initialization
  for (int i = 0; i < MAX_ASCII_VALUE; ++i)
    char_frequency[i] = 0;

  //loop

  for (int j = 0; j < strlen(input); ++j){
    c = input[j];
    ++char_frequency[c];
  }

  printf("CHAR FREQUENCY\n");

  for (int index = 1; index < MAX_ASCII_VALUE; ++index){
    if (index <= 'z' && index >= 'A'){
      printf("%c:\t\b\b", index);
      for(int count = char_frequency[index]; count > 0; --count){
        printf("#");
      }
      printf("\n");
    }
  }

}

