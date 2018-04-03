//
//  exercise-1-17-print-lines-longer-than-80-chars.c
//  
//
//  Created by uah on 10.03.18.
//

#include <stdio.h>
#define MIN_LINE_LENGTH_TO_PRINT    80      /* All lines longer than this size will be printed */
#define MAX_LINE                    1000    /* What is the max array size we can allocate */

int     getOneLine(char line[], int max);
void    printLine(char line[], int len);
int     removeTailingSpaces(char line[], int len);
int     isBlank(char line[], int len);

int main() {
    int len;
    
    char line[MAX_LINE];
    
    // put each line in an array
    while((len = getOneLine(line, MAX_LINE)) > 0) {
        // remove the trailing white spaces
        len = removeTailingSpaces(line, len);
        // print only the blank lines
        if (!isBlank(line, len)) {
            printLine(line, len);
        }
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

    printf("Printed line: ");

    for (i = 0; i <= len - 1; i++) {
        putchar(line[i]);
    }
}

int isBlank(char line[], int len) {
    int i;

    if (line[0] == '\n') {
        return 1;
    } else {
        return 0;
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