// Exercise 1-19.
// Write a function reverse (s) that reverses the character strings.
// Use it to write a program that reverses its input a line at a time.

#include <stdio.h>
#define MIN_LINE_LENGTH_TO_PRINT    80      /* All lines longer than this size will be printed */
#define MAX_LINE                    1000    /* What is the max array size we can allocate */

int     getOneLine(char line[], int max);
void    printLine(char line[], int len);
int     removeTailingSpaces(char line[], int len);
int     reverse(char line[], int len);

int main() {
    int len;
    
    char line[MAX_LINE];
    
    // put each line in an array
    while((len = getOneLine(line, MAX_LINE)) > 0) {
        // remove the trailing white spaces
        len = removeTailingSpaces(line, len);
        // before printing, reverse the line.
        reverse(line, len);
        printLine(line, len);
    }
}

/**
 * Using getchar will fill provided empty array with content.
 * 
 * @param  line      Array tp fill
 * @param  maxLenght Don't overfill the array with content bigger than it's size
 * @return           What is the size of the read line
 */
int getOneLine(char line[], int maxLenght) {
    int i, c;
    
    for (i = 0; i < maxLenght - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    
    // inserts NULL at the end.
    line[i] = '\0';
    
    return i;
}

/**
 * Gets an array of characters and prints it to the stdout.
 * 
 * @param line The array to print
 * @param len  What is the length of the array
 */
void printLine(char line[], int len) {

    int i;

    for (i = 0; i <= len - 1; i++) {
        putchar(line[i]);
    }
}

int removeTailingSpaces(char line[], int len) {
    int i;

    for (i = 0; line[i] == '\t' || line[i] == ' '; ++i) {
        line[i] = '\0';
    }

    // checking backwards if the there are any whitespaces and if so, remove them
    for (i = len - 1; line[i] == ' ' || line[i] == '\t'; --i) {
        line[i] = '\0';
    }

    line[++i] = '\n';

    return i;
}

int reverse(char line[], int len) {
    int i;
    char temp;

    // printf("Reversing len %d\n", len);
    // printf("Half is %d\n", len / 2);

    for (i = 0; i < len / 2; i++) {
        // printf("%c[], %d \n", line[i], i);
        temp = line[(len - 1) - i];
        line[(len - 1) - i] = line[i];
        line[i] = temp;
    }

    return 0;
}