// Exercise 1-24.
// Write a program to check a C program for rudimentary syntax
// errors like unbalanced parentheses, brackets and braces. Don't forget about
// quotes, both single and double, escape sequences, and comments.
// (This pro- gram is hard if you do it in full generality.)

// Solution:
// We count how many special chars we open and we close, then we compare the count.
// To track many characters' counters, we use external variables.
// We don't count anything that is part of a comment or a "string"
// 
// Problem:
// This won't catch cases where we first close the char and then we open it (][)
#include <stdio.h>

#define MAXLINELENGTH 1000

int getoneline(char line[], int len);
void checkForSyntaxErrors(char line[], int len);
int isClosingCommentBlock(char currentChar, char nextChar);
int isStartOfComment(char currentChar, char nextChar);
void countChars(char currentChar, char prevChar);
void printErrorCount(int openCounter, int closingCounter, char item[]);

int isInComment = 0;
int isBlockOfComment = 0;

// Count how many special chars ({, [, (, " and ') we open and close.
// This has a week spot because we we could have a closing char even having an opening
// one. This should be tracked somehow too.
int openParenthesesCount = 0;
int openBracketsCount = 0;
int openBracesCount = 0;
int openQuotesCount = 0;
int openDoubleQuotesCount = 0;

// To avoid issues where we have a more closing symbols than opening ones,
// we should track how many characters we close separately from the opening tracking.
int closedParenthesesCount = 0;
int closedBracketsCount = 0;
int closedBracesCount = 0;
int closedQuotesCount = 0;
int closedDoubleQuotesCount = 0;


int hasOpeningQuotes = 0;
int hasOpeningDoubleQuotes = 0;
int printedIssuesCount = 0;

int main() {
  int len;
  char line[MAXLINELENGTH];


  while ((len = getoneline(line, MAXLINELENGTH)) > 0) {
    // printf("Line to check: %s", line);
    checkForSyntaxErrors(line, len);
  }

  // print the end result
  printErrorCount(openParenthesesCount, closedParenthesesCount, "parentheses");
  printErrorCount(openBracketsCount, closedBracketsCount, "brackets");
  printErrorCount(openBracesCount, closedBracesCount, "braces");
  printErrorCount(openQuotesCount, closedQuotesCount, "quotes");
  printErrorCount(openDoubleQuotesCount, closedDoubleQuotesCount, "doble quotes");

  if (!printedIssuesCount) {
    printf("Congratulations! Everything seems fine.\n");
  }
}

void printErrorCount(int openCounter, int closingCounter, char item[]) {
  extern int printedIssuesCount;
  if (openCounter > closingCounter) {
    printedIssuesCount++;
    printf("Error: You have %d non closed %s.\n", openCounter - closingCounter, item);
  } else if (openCounter < closingCounter) {
    printedIssuesCount++;
    printf("Error: You have %d non opened %s.\n", closingCounter - openCounter, item);
  } else {
    printf("Your closing and opening %s are equal.\n", item);
  }
}

int getoneline(char line[], int len) {
  int i;
  char c;

  for (i = 0; i < len; i++) {
    if ((c = getchar()) != EOF && c != '\n') {
      line[i] = c;
    } else {
      break;
    }
  }

  if (c == '\n') {
    line[i] = c;
    i++;
  }

  return i;
}

int isClosingCommentBlock(char currentChar, char nextChar) {
  if (currentChar == '*' && nextChar == '/') {
    return 1;
  } else {
    return 0;
  }
}

int isStartOfComment(char currentChar, char nextChar) {
  extern int isBlockOfComment;

  int result = 0;

  if (currentChar == '/' && (nextChar == '/' || nextChar == '*')) {
    result = 1;

    if (nextChar == '*') {
      isBlockOfComment = 1;
    }
  }

  return result;
}

void countChars(char currentChar, char prevChar) {

  extern int openParenthesesCount;
  extern int openBracketsCount;
  extern int openBracesCount;
  extern int quotesCount;
  extern int openDoubleQuotesCount;

  extern int closedParenthesesCount;
  extern int closedBracketsCount;
  extern int closedBracesCount;
  extern int closedQuotesCount;
  extern int closedDoubleQuotesCount;

  extern int hasOpeningDoubleQuotes;
  extern int hasOpeningQuotes;

  // in case the character is not escaped
  // or not part of a "string"
  if (prevChar != '\\' && !hasOpeningQuotes && !hasOpeningDoubleQuotes) {
    switch(currentChar) {
      case '{':
        openBracesCount++;
        break;
      case '}':
        closedBracesCount++;
        break;

      case '(':
        openParenthesesCount++;
        break;
      case ')':
        closedParenthesesCount++;
        break;

      case '[':
        openBracketsCount++;
        break;
      case ']':
        closedBracketsCount++;
        break;

      case '"':
        hasOpeningDoubleQuotes = 1;
        openDoubleQuotesCount++;
        break;

      case '\'':
        hasOpeningQuotes = 1;
        openQuotesCount++;
        break;

      default:
        break;
    }
  // In case there is an opening string char, we check for a closing one without
  // counting anything opening and closing from the rest of the special chars.
  } else if (prevChar != '\\' && (hasOpeningQuotes || hasOpeningDoubleQuotes)) {
    if (currentChar == '"' && hasOpeningDoubleQuotes) {
      hasOpeningDoubleQuotes = 0;
      closedDoubleQuotesCount++;
    } else if (currentChar == '\'' && hasOpeningQuotes) {
      hasOpeningQuotes = 0;
      closedQuotesCount++;
    }
  }
}

void checkForSyntaxErrors(char line[], int len) {
  extern int isInComment;
  extern int isBlockOfComment;

  int i;

  for (i = 0; i < len; i++) {
    if (isInComment) {
      // if we are still in a comment, we should look for closing "*/"
      // in case the type of comment is "/*...*/"
      if (isBlockOfComment && isClosingCommentBlock(line[i], line[i + 1])) {
        // tells the loop to stop removing characters.
        isInComment = 0;
        isBlockOfComment = 0;
      }

      if (line[i] == '\n' && !isBlockOfComment) {
        isInComment       = 0;
        isBlockOfComment  = 0;
      }
    } else if (isStartOfComment(line[i], line[i + 1])) {
      isInComment = 1;
    } else {
      // in case we are not in a comment, just count the characters.
      countChars(line[i - 1], line[i]);
    }
  }
}