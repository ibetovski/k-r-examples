//
//  copy-file-replace-blanks.c
//  
//
//  Created by uah on 4.03.18.
//

#include <stdio.h>

/*
     This file will read a file and will print it to standard out by replacing:
     tab with \t
     backspace with \b
     backslash with \\
 */
int main() {
    
    int c;
    
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
    
    return 0;
}
