//
//  section1-9-char-array-getline.c
//  
//
//  Created by uah on 9.03.18.
//
// This program will read many long lines from the standard input and will
// print the longest one.

#include <stdio.h>
#define MAXLINE 1000

int getoneline(char line[], int maxline);
void copyto(char to[], char from[]);

int main() {
    // variables used for comparasion between current line's length and the longest line length
    int     len;
    int     max;
    
    // keeps the current found line. The length of the array if the max defined at the top
    char    line[MAXLINE];
    
    // Keeps the longest line.
    char    longest[MAXLINE];
    
    max = 0;
    
    printf("Please enter a few lines of text and press Ctrl-D or Ctrl-Z:\n");
    
    // getline works in an interesting way. It gets empty array and fills it while
    // reads the standard input.
    // And this while loop won't finish until the getline stops producing new lines.
    while((len = getoneline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copyto(longest, line);
        }
    }
    
    if (max > 0) {
        printf("The longest line is:\n");
        printf("%s", longest);
        printf("Length of the string: %d\n", max);
    }
    
    return 0;
}


/**
 Reads the standard input and when there is a new line, stops.
 Keeps the line chars in an array provided from outside of the function.

 Note: This function is names getoneline instead of getline because getline seems to be
 part of the standard library and it provokes an error:
 conflicting types for 'getline'

 @param s placeholder for the line that was just read
 @param lim what is the max limit of long line. If the line is longer than that
 the algorithm will cut it off.
 @return The number of character of the extracted line.
 */
int getoneline(char s[], int lim) {
    int c, i;
    
    // this will copy each character of the line into the placeholder unless the current char
    // is a new line
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    
    // if it is, it will be added to the end of the string array.
    if (c == '\n') {
        s[i] = c;
        ++i;
    } else {
        // Exercise 1-16. Revise the main routine of the longest-line program so
        // it will correctly print the length of arbitrarily long input lines,
        // and as much as possible of the text.
        while((c = getchar()) != EOF && c != '\n') {
            ++i;
        }
    }
    
    // put a null value at the end of the line.
    s[i] = '\0';
    return i;
}

/**
 Will keep the line into a separate placeholder. This is used for keeping the longest
 line only when it appears.

 @param to Placeholder where to put the current longest line
 @param from Array which to get the string from
 */
void copyto(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
