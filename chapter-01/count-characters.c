//
//  count-characters.c
//  
//
//  Created by uah on 4.03.18.
//

#include <stdio.h>

/**
 Reads standard input and count the characters.

 @return int
 */
int main() {
    
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    
    printf("Total length of the string is: %.0f\n", nc);
    return 0;
}
