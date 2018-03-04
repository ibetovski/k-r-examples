//
//  temperature.c
//  
//
//  Created by uah on 4.03.18.
//

#include <stdio.h>

#define LOWER   0 /* What is the lowest fahrenheit value to print */
#define UPPER 300 /* What is the top border for the same */
#define STEP   20 /* What is the step to move to the next value */

/* Will print fahrenheit to celsius:
 for fahr = 0, 20, 40, ..., 300 */
int main() {
    
    float   fahr;
    
    printf("%s\t%s", "Fahrenheit", "Celsius\n");
    printf("---------------------------\n");
    
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%10.0f\t%6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
    }
    return 0;
}
