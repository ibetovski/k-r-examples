//
//  wc-wanna-be.c
//  
//
//  Created by uah on 5.03.18.
//

#include <stdio.h>

#define IN  0 /* inside a word */
#define OUT 1 /* outside a word */


/**
 Count lines, words and characters in input

 @return nothing special
 */
int main() {
    
    int c, nl, nw, nc, state;
    
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    
    printf("\t%d\t%d\t%d\n", nl, nw, nc);
    
    return 0;
}
