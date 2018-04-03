//
//  celsius-to-fahrenheit.c
//  
//
//  Created by uah on 4.03.18.
//

#include <stdio.h>


/**
 Prints table of values from degress of celsius to fahrenheit.

 @return int
 */
int main() {
    float   fahr, celsius;
    int     lowest, upper, step;
    
    lowest  = -20;
    upper   =  80;
    step    =   20;
    
    celsius = lowest;
    
    while (celsius <= upper) {
        fahr = celsius * 9.0/5.0 + 32.0;
        printf("%3.0f\t%3.1f\n", celsius, fahr);
        
        celsius = celsius + step;
    }
    
    return 0;
}
