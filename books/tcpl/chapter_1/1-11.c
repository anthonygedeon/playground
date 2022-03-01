#include <stdio.h>                                                 

#define IN_WORD 1
#define NOT_IN_WORD 0

void main(void) {
        int c;

        int nl = 0;
        int nw = 0;
        int nc = 0;
        int state = NOT_IN_WORD;
        
        while((c = getchar()) != EOF) {
            ++nc;
            if (c == '\n') {
                ++nl;
            }   
            if (c == ' ' || c == '\n' || c == '\t') {
                state = NOT_IN_WORD;
            } else if (state == NOT_IN_WORD) {
                state = IN_WORD;
                ++nw; 
            }   
        
        }
        printf("%d %d %d\n", nl, nw, nc);
}

// Q: How would you test the word count program
// A: First I would have broken this main function into more primitive functions
// i.e get_character_count, get_word_count, and lastly get_line_count then I
// would test the input and see if I have a satisfactory assertion 
// For example: get_word_count("hello world") == 2

// Q: What kinds of inputs are mostly to uncover bugs if there are any?
// A: 1. only \n's
//    2. no input 
//    3. only \t's  


