#include <stdio.h>
#include <stdlib.h>

// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments don't nest.

#define INITIAL_STATE 0
#define LOOKUP_STATE 1
#define SCOMMENT_STATE 2
#define MCOMMENT_STATE 3
#define CLOSE_MCOMMENT_STATE 4
#define QUOTE_STATE 5
#define TOTAL_STATES 6

#define FSM_MACRO FSM[TOTAL_STATES][128]


void remove_comments(char line[], char FSM_MACRO);
void create_transitions(char state[], int default_state, char inputs[], int states[]);
void create_fsm(char FSM_MACRO);

int main(void)
{  // this is a test
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("1.10/1-23.c", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);


  // FSM Initialization

  char FSM_MACRO;
  create_fsm(FSM);

  char not_comment[] = "// yunooo";



  while /* remove */ ((read = getline(&line, &len, fp)) != -1) {
    remove_comments(line, FSM);
    printf("%s", line);
  }

  fclose(fp);
  if (line)
    free(line);
  exit(EXIT_SUCCESS);

  return 0;
}

void create_transitions(char state[], int default_state, char inputs[], int trans_states[])
{
  char c;

  for (int i = 0; i <= 128; ++i)
    state[i] = default_state;

  for (int i = 0; (c = inputs[i]) != '\0'; ++i)
    state[c] = trans_states[i];
}

void create_fsm(char FSM_MACRO)
{
  char x6[] = {'"'};
  int y6[] = {INITIAL_STATE};
  create_transitions(FSM[5], 5, x6, y6);

  char x4[] = {'*'};
  int y4[] = {CLOSE_MCOMMENT_STATE};
  create_transitions(FSM[MCOMMENT_STATE], MCOMMENT_STATE, x4, y4);

  char x5[] = {'/'};
  int y5[] = {INITIAL_STATE};
  create_transitions(FSM[CLOSE_MCOMMENT_STATE], CLOSE_MCOMMENT_STATE, x5, y5);

  char x1[] = {'/', '"'};
  int y1[] = {LOOKUP_STATE, QUOTE_STATE};
  create_transitions(FSM[INITIAL_STATE], INITIAL_STATE, x1, y1);

  char x2[] = {'/', '*'};
  int y2[] = {SCOMMENT_STATE, MCOMMENT_STATE};
  create_transitions(FSM[LOOKUP_STATE], LOOKUP_STATE, x2, y2);

  char x3[] = {'\0'};
  int y3[] = {'\0'};
  create_transitions(FSM[SCOMMENT_STATE], SCOMMENT_STATE, x3, y3);


}


void remove_comments(char line[], char FSM_MACRO)
{
  int state = INITIAL_STATE, j=0;
  char c;

  /* printf(val: %d\n, FSM[MCOMMENT_STATE]['']); */
  for (int i = 0; (c = line[i]) != '\0'; ++i)
  {
    /* printf("char: %c, state: %d\n", c,state); */
    if (state == INITIAL_STATE)
    {
      state = FSM[state][c];
      line[j] = line[i];
      ++j;
    }
    else if (state == LOOKUP_STATE)
    {
      state = FSM[state][c];

      if (state == MCOMMENT_STATE || state == SCOMMENT_STATE)
      {
        --j;
        line[i-1] = line[i] = ' ';
      }
      else
        ++j;

    }
    else if (state == SCOMMENT_STATE)
    {
      state = FSM[state][c];
      if (line[i + 1] == '\0')
        if (line[i] == '\n' || line[i] == '\r')
          {
            line[j] = line[i];
            ++j;
          }

    }


    else if (state == MCOMMENT_STATE || state == CLOSE_MCOMMENT_STATE)
    {
      state = FSM[state][c];
      if (line[i + 1] == '\0')
        if (line[i] == '\n' || line[i] == '\r')
          {
            line[j] = line[i];
            ++j;
          }
    }

    else if (state == QUOTE_STATE)
    {
      state = FSM[state][c];  // tes
      line[j] = line[i];
      ++j;
    }
  }
  line[j] = '\0';
}
