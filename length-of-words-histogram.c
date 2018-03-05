//
//  length-of-words-histogram.c
//  
//
//  Created by uah on 5.03.18.
//

#include <stdio.h>
#define IN  0
#define OUT 1


/**
 Task:
 Write a program to print a histogram of the lengths of words in its input.
 It is easy to draw the histogram with the bars horizontal; a vertical orientation
 is more challenging.

 @return int
 */
int main() {
    
    int c, i, j, state;
    
    // there should be a placeholder for the words counts.
    // We will use max 10 words.
    int wordsLength[10];
    
    // each word will start with length 0 by default:
    for (i = 0; i < 10; ++i) {
        wordsLength[i] = 0;
    }
    
    state = OUT;
    i = 0;
    
    while ((c = getchar()) != EOF) {
        if (state == IN) {
            ++wordsLength[i];
        }
        
        // we should count each word's length when it starts and when it ends.
        if (c == '\t' || c == ' ' || c == '\n') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            // when we start a new word, we should start counting it.
            ++i;
        }
    }
    
    // lets print a horizontal histogram for each word.
    printf("Words length historgram:\n");
    for (i = 0; i < 10; ++i) {
        // don't print anything for not used placeholders for counting words.
        if (wordsLength[i] == 0) {
            continue;
        }
        
        for (j = 0; j < wordsLength[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }
    
    return 0;
}
