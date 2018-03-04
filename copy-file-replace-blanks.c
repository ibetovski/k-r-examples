//
//  copy-file-replace-blanks.c
//  
//
//  Created by uah on 4.03.18.
//

#include <stdio.h>


/**
 Will print a blank where there is one or more blanks.
 The code is solution to an exercise from the book.

 @return int
 */
int main() {
    
    int c, lastChar;
    
    while((c = getchar()) != EOF) {
        if (c != ' ') {
            if (lastChar == ' ') {
                putchar(' ');
            }
            putchar(c);
        } else {
            lastChar = ' ';
        }
        
        lastChar = c;
    }
    
    return 0;
}
