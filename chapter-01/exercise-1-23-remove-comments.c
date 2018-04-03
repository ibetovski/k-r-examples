// Exercise 1-23.
// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly.
// C comments do not nest.
#include <stdio.h>

#define MAXLINE 1000

// input/output methods
int   getoneline(char line[], int len);
void  printLine(char line[], int len);

// helpers
int  stripComments(char line[], int len);

int isInComment = 0;
int shouldBeStop = 0;

int main() {
  char line[MAXLINE];
  int len;

  while((len = getoneline(line, MAXLINE)) > 0) {
    // amend the line by removing the comments on the lines
    len = stripComments(line, len);
    // Print the line only if we not in a comment anymore.
    // if (len > 0) {
      printLine(line, len);
    // }
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

/**
 * Will strip any type of comments from one line.
 * This function works cross lines by accessing external variables to check if the
 * current line we are is still in a comment mode.
 * 
 * @param line              The array of text to check for comments
 * @param len               What is the text's length
 */
int stripComments(char line[], int len) {

  extern int isInComment;
  extern int shouldBeStop;

  int i;

  for (i = 0; i < len; i++) {
    if (isInComment) {
      // if we are still in a comment, we should look for closing "*/"
      // in case the type of comment is "/*...*/"
      if (shouldBeStop && line[i] == '*' && line[i + 1] == '/') {
        // tells the loop to stop removing characters.
        isInComment = 0;
        shouldBeStop = 0;

        // make sure we will remove the next character too, because it should be part
        // of the comment.
        line[i + 1] = '\0';
      }

      if (line[i] != '\n') {
        line[i] = '\0';
      } else if (!shouldBeStop) {
        isInComment = 0;
        shouldBeStop = 0;
      }
    } else if (line[i] == '/' && (line[i + 1] == '/' || line[i + 1] == '*')) {

      if (line[i + 1] == '*') {
        shouldBeStop = 1;
      }

      isInComment = 1;

      // when the inline comment has marked as started, this happens usually
      // on the second slash from "//" so we should remove both of them.
      line[i] = '\0';
    }
  }

  return len;
}

void printLine(char line[], int len) {
  int i;

  for (i = 0; i < len; i++) {
    putchar(line[i]);
  }
}