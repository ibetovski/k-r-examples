// Exercise 1-21:
// Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing. Use the same tab stops as for
// detab.
// When either a tab or a single blank woulds uffice to reach a tab stop,
// which should be given preference?
#include <stdio.h>

#define MAXLINE 1000
#define SPACES_PER_TAB 4
#define TAB_CHAR '\t'

int getoneline(char line[], int len);
int printline(char line[], int len);

int main() {
  char line[MAXLINE];
  int len;

  // Make the user understand what is expected from him:
  printf("If you enter a text, each %d spaces in the text will be replaced with one TAB.\n", SPACES_PER_TAB);
  printf("So enter/paste any text with spaces and press ENTER...\n");

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
  int inneri;
  int spaces;

  for (i = 0; i < len; i++) {
    // if there is a blank space,
    // count how many blanks are after each other.
    // If there are 4, put a tab on it's place and continue iterating from it.
    if (line[i] == ' ') {
      inneri = i;
      while (inneri < i + SPACES_PER_TAB) {
        if (line[inneri] == ' ') {
          inneri++;
        } else {
          break;
        }
      }

      // if the spaces are 4 after each other, put just one tab char.
      if (inneri == i + SPACES_PER_TAB) {
        putchar(TAB_CHAR);
        // continue reading the line after the counter tabs.
        i = inneri - 1;
      } else {
        putchar(' ');
      }
    } else {
      putchar(line[i]);
    }
  }

  return 0;
}
