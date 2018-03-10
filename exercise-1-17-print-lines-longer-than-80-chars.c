//
//  exercise-1-17-print-lines-longer-than-80-chars.c
//  
//
//  Created by uah on 10.03.18.
//

#include <stdio.h>
#define MIN_LINE_LENGTH_TO_PRINT    80      /* All lines longer than this size will be printed */
#define MAX_LINE                    1000    /* What is the max array size we can allocate */

int getoneline(char line[], int max);

int main() {
    int len;
    
    char line[MAX_LINE];
    
    while((len = getoneline(line, MAX_LINE)) > 0) {
        if (len > MIN_LINE_LENGTH_TO_PRINT) {
            printf("LINE LONGER THAN %d characters: %s\n", MIN_LINE_LENGTH_TO_PRINT, line);
        }
    }
}

int getoneline(char line[], int maxLenght) {
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
