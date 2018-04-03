//
//  print-one-word-per-line.c
//  
//
//  Created by uah on 5.03.18.
//

#include <stdio.h>
#define IN  1
#define OUT 0


/**
 This program is meant to read standard input and to print a word per line.

 @return int
 */
int main() {
    
    int c, state;
    
    state = OUT;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state != OUT) {
                putchar('\n');
            }
            state = OUT;
        } else if (state == OUT) {
            putchar(c);
            state = IN;
        } else {
            putchar(c);
        }
    }
    return 0;
}
