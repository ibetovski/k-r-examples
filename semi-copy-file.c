//
//  semi-copy-file.c
//  
//
//  Created by uah on 4.03.18.
//

#include <stdio.h>


/**
 Rads file from standard input and prints the content character by character
 into the standard output.

 @return int
 */
int main() {
    
    int c;
    
    printf("End of file is: %d\n", EOF);
    
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    
    return 0;
}
