// Exercise 1-22:
// Write a program to "fold" long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of input.
// Make sure your program does something intelligent with very long lines,
// and if there are no blanks or tabs before the specified column
// ----------------------
// 
// Solution to long lines without any blank spaces:
// Write a function that inserts a new element on a specified position
// in an array by shifting the elements with one position. This is to fultil the
// requirement for something inteligent when there are no blanks before the column
// to fold on.
// 
// I want to insert "-\n"

#include <stdio.h>

#define MAXLINE 1000
#define COLUMN_TO_FOLD_ON 40
#define SPACES_PER_TAB 4
#define TAB_CHAR '\t'

int getoneline(char line[], int len);
int printline(char line[], int len);
void insertInArray(char itemToInsert, int positionToInsertOn, char line[], int len);
void foldLine(char line[], int len);


int main() {
  char line[MAXLINE];
  int len;

  int isTitlePrinted = 0;

  while((len = getoneline(line, MAXLINE)) > 0) {
    if (!isTitlePrinted) {
      printf("\n\n --- Here is the output (folded on %d column): ---\n\n", COLUMN_TO_FOLD_ON);
      isTitlePrinted = 1;
    }

    if (len > COLUMN_TO_FOLD_ON) {
      foldLine(line, len);
    }

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

/**
 * Shifts each element in an array with one position to makes a space on a specified
 * position which will be filled with a provided char.
 * 
 * @param itemToInsert       Which char to put on the new empty position
 * @param positionToInsertOn Which position to star the shifting from
 * @param line               The array to amend
 * @param len                The length of the text in that array
 */
void insertInArray(char itemToInsert, int positionToInsertOn, char line[], int len) {
  // iterates the array from back to beginning and moves each char with one
  // place forward.
  int i;

  for (i = len - 1; i >= positionToInsertOn; i--) {
    line[i + 1] = line[i];
  }

  line[positionToInsertOn] = itemToInsert;
}

/**
 * Puts new line character on the last blank space before the column to fold on.
 * In case there are no any blank spaces, will put '-' and a new line on the
 * column to fold on.
 * 
 * @param line The text to amend
 * @param len  The length of the same text
 */
void foldLine(char line[], int len) {
  int i;
  // will track the index after the folded element.
  int inneri;
  int lastFoundSpaceIndex;

  // by setting the default index to -1 we will check when the column to fold is
  // reached if that index is still -1, this will mean there wasn't any blank
  // character to fold the text on.
  lastFoundSpaceIndex = -1;
  inneri = 0;

  for (i = 0; i < len; i++) {

    if ((line[i] == ' ' || line[i] == '\t') && inneri <= COLUMN_TO_FOLD_ON) {
      lastFoundSpaceIndex = i;
    }

    if (inneri++ == COLUMN_TO_FOLD_ON) {
      if (lastFoundSpaceIndex > -1) {
        line[lastFoundSpaceIndex] = '\n';
      } else {
        // if there are no any blank spaces before the column to fold on,
        // insert "-" and a new line.
        insertInArray('-', i, line, len);
        insertInArray('\n', i + 1, line, len);
      }

      inneri = 0;
    }
  }
}

/**
 * Before printing the line will count how many characters are printed and if the
 * 40 columns are passed, will start looking for the first blank character (space or tab)
 * to break the line into more lines.
 * 
 * @param  line 
 * @param  len  
 * @return void
 */
int printline(char line[], int len) {
  int i;
  
  for (i = 0; i < len; i++) {
    putchar(line[i]);
  }

  return 0;
}