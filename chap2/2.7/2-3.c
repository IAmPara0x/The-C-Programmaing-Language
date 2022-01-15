#include <stdio.h>
#include <string.h>

int htoi(const char s[])
{
  int n = 0, value = 0, offset = 0;
  char c;
  char esc_chars[][2] = {"0X", "0x"};

  if (!(strncmp(s, esc_chars[0], 2) ||
        strncmp(s, esc_chars[1], 2)
        )
      )
    offset = 2;
  else
    offset = 0;

  for (offset = offset; (c = s[offset]) != '\0'; ++offset)
  {
    if (c >= '0' && c <= '9')
      value = c - '0';
    else if (c >= 'a' && c <= 'f')
      value = c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
      value = c - 'A' + 10;
    n = 16 * n + value;
  };

  return n;
}

int main()
{
  char s[] = "0xabe978f";
  printf("Value of `%s` : %d, %d\n", s, htoi(s), 0xabe978f);
  return 0;
}
