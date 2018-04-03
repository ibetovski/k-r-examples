//
//  length-of-words-histogram-vertical.c
//  
//
//  Created by uah on 6.03.18.
//

#include <stdio.h>
#define IN  0
#define OUT 1

// 10, because this is the total height
#define MAX_HISTOGRAM_HEIGHT 10

// how many words to count
// (this is until
#define MAX_WORDS_COUNT 20


/**
 Task:
 Write a program to print a histogram of the lengths of words in its input.
 It is easy to draw the histogram with the bars horizontal; a vertical orientation
 is more challenging.
 
 @return int
 */
int main() {
    
    int c, i, j, row, state;
    
    // there should be a placeholder for the words counts.
    // We will use max 10 words.
    int wordsLength[MAX_WORDS_COUNT];
    
    // each word will start with length 0 by default:
    for (i = 0; i < MAX_WORDS_COUNT; i++) {
        wordsLength[i] = 0;
    }
    
    state = OUT;
    
    // we use -1 because the script will increase the index before start
    // counting the characters of the words.
    i = -1;
    
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
    
    // lets print a vertical histogram for each word.
    printf("Words length historgram:\n");
    
    for (row = 0; row < MAX_HISTOGRAM_HEIGHT; row++) {
        // we will iterate each word and will print the histogram char only
        // if the row we are on is more than the total histogram height minus
        // the word's lenght
        for (i = 0; i < MAX_WORDS_COUNT; i++) {
            if (row >= MAX_HISTOGRAM_HEIGHT - wordsLength[i]) {
                printf("x");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    return 0;
}
