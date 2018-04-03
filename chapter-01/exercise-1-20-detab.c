// Exercise 1-20:
// Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops,
// say every n columns. Should n be a variable or a symbolic parameter?
#include <stdio.h>

#define MAXLINE 1000
#define SPACES_PER_TAB 8
#define SPACE_CHAR '.'

int getoneline(char line[], int len);
int printline(char line[], int len);

int main() {
  char line[MAXLINE];
  int len;

  while((len = getoneline(line, MAXLINE)) > 0) {
    printline(line, len);
  }
}

int getoneline(char line[], int len) {
  int i = 0;
  char c;
  while ((c = getchar()) != EOF && c != '\n') {
    line[i] = c;
    i++;
  }

  if (c == '\n') {
    line[i] = c;
    i++;
  }

  return i;
}

int printline(char line[], int len) {
  int i;
  int spaces;

  for (i = 0; i < len; i++) {
    if (line[i] == '\t') {
      spaces = SPACES_PER_TAB;
      // printf("TAB");
      while(spaces > 0) {
        putchar(SPACE_CHAR);
        spaces--;
      }
    } else {
      putchar(line[i]);
    }
  }

  return 0;
}
