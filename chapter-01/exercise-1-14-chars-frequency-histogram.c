//
//  exercise-1-14-chars-frequency-histogram.c
//  
//
//  Created by uah on 6.03.18.
//

#include <stdio.h>
#define IN  0
#define OUT 1

// 10, because this is the total height
#define MAX_HISTOGRAM_HEIGHT 10

// Having the low and top boudaries for both upper and lower case we can
// count each character's frequency in a case insensitive manner.
#define LOW_LETTERS_BOUNDARY_UPPERCASE  65
#define TOP_LETTERS_BOUNDARY_UPPERCASE  90
#define LOW_LETTERS_BOUNDARY_LOWERCASE  97
#define TOP_LETTERS_BOUNDARY_LOWERCASE 122


/**
 Task:
 Having an input of words print a histogram of the characters frequency.
 
 @example:
 echo "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi urna lorem, commodo vitae fermentum nec, egestas sit amet magna. Nam." | ./build/exercise-1-14-chars-frequency-histogram.out
 
 Will print:
 
 Words length histogram:
 x               x           x
 x       x       x       x   x         x
 x       x       x       x   x         x
 x       x       x       x x x     x x x
 x       x       x       x x x     x x x
 x   x   x       x       x x x     x x x
 x   x   x       x     x x x x     x x x x
 x   x x x   x   x     x x x x     x x x x
 x   x x x   x   x     x x x x x   x x x x
 x x x x x x x   x     x x x x x   x x x x x
 a b c d e f g h i j k l m n o p q r s t u v w x y
 
 @return int
 */
int main() {
    
    // use it for loops
    int i,
        // a placeholder for input character from standard input.
        c,
        // use it for looping thought each histogram row.
        row,
        // use it to create the needed array length.
        totalLettersCount;
    
    totalLettersCount = TOP_LETTERS_BOUNDARY_UPPERCASE - LOW_LETTERS_BOUNDARY_UPPERCASE;
    // there should be a placeholder for the words counts.
    // We will use max 10 words.
    int frequency[totalLettersCount];
    
    // each letter by default is repeating 0 types.
    // we will increase them later.
    for (i = 0; i < totalLettersCount; i++) {
        frequency[i] = 0;
    }
    
    // reading the user's input
    while ((c = getchar()) != EOF) {
        // we are interested only in the letters.
        if (
            (c >= LOW_LETTERS_BOUNDARY_UPPERCASE && c <= TOP_LETTERS_BOUNDARY_UPPERCASE) ||
            (c >= LOW_LETTERS_BOUNDARY_LOWERCASE && c <= TOP_LETTERS_BOUNDARY_LOWERCASE)
        ) {
            if (c <= TOP_LETTERS_BOUNDARY_UPPERCASE) {
                // having the character's number when we substract the
                // uppercase A's number from it, we get 0.
                ++frequency[(c - LOW_LETTERS_BOUNDARY_UPPERCASE)];
            }
            else if (c >= LOW_LETTERS_BOUNDARY_LOWERCASE) {
                // having the character's number when we substract the
                // a's number from it, we get 0 again.
                // this way no matter the case we count each letter's frequency.
                ++frequency[(c - LOW_LETTERS_BOUNDARY_LOWERCASE)];
            }
        }
    }

    // lets print a vertical histogram for each word.
    printf("Characters frequency histogram:\n");

    for (row = 0; row < MAX_HISTOGRAM_HEIGHT; row++) {
        // we will iterate each word and will print the histogram char only
        // if the row we are on is more than the total histogram height minus
        // the word's lenght
        for (i = 0; i < totalLettersCount; i++) {
            if (row >= MAX_HISTOGRAM_HEIGHT - frequency[i]) {
                printf("x ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    // print each letter for a better clarity what we see on the histogram
    for (i = 0; i < totalLettersCount; i++) {
        printf("%c ",(i + LOW_LETTERS_BOUNDARY_LOWERCASE));
    }
    
    printf("\n");
    
    return 0;
}
