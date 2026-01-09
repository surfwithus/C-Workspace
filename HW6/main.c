// A program template for your homework solution
// You can use the following template

#include <stdio.h>
#include <string.h>

typedef enum {
    START,
    STATE1,
    STATE2,
} State;

int process_word(const char*);

int main(void) {
    char input[] = "A CL KL COL KOL COKOO COOOOOL KOAHL COCOCOCOL CKOL CL COKOOOOOOOL CL KOOOOOCL COLLCOL POKCM WKRCO COCOCOCOL KCKCKCOL KOKOLKOL KL CCOCL COOOOO";
    char* word;
    word = strtok(input, " ");

    while (word != NULL) {
        int result = process_word(word);
        printf("%d", result);  // print outcomes
        word = strtok(NULL, " ");
    }
    return 0;
}

int process_word(const char* word) {
    // Implement your code as here
    State state = START;
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        char c = word[i];

        switch (state) {
            case START:
                if (c == 'C' || c == 'K') {
                    state = STATE1;
                }
                else return 0;
                break;
            case STATE1:
                if (c == 'O')
                    state = STATE2;
                else return 0;
                break;
            case STATE2:
                if (c == 'C' || c == 'K')
                    state = STATE1;
                else if (c == 'O')
                    state = STATE2;
                else if (c == 'L' && word[len-1] == 'L')
                    return 1;
                else return 0;
                break;
        }
    }

    // Test code that prints the word //
    // for (int i = 0; i < strlen(word); i++) {
    //     printf("%c", word[i]);
    // }
    // printf("\n");
    // Rnd of test code
    return 0;
}