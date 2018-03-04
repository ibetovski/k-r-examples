//
//  line-counting.c
//  
//
//  Created by uah on 4.03.18.
//

#include <stdio.h>


/**
 Will count new lines, tabs and blanks in a text read from standard input.

 @return int
 */
int main() {
    
    int c, t, b, nl;
    
    nl  = 0;
    t   = 0;
    b   = 0;
    
    
    printf("%d\n", '\t');
    
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        } else if (c == '\t') {
            ++t;
        } else if (c == ' ') {
            ++b;
        }
    }
    
    printf("New lines: %d\n",   nl);
    printf("Tabs: %d\n",        t);
    printf("Blanks: %d\n",      b);
    
    return 0;
}
