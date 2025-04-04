#include <stdio.h>
#include <string.h>

void stuff(char *input, char *output) {
    int count = 0;
    for (int i = 0, j = 0; input[i]; i++) {
        output[j++] = input[i];
        if (input[i] == '1' && ++count == 5) {
            output[j++] = '0';
            count = 0;
        } else if (input[i] == '0') {
            count = 0;
        }
    }
}

void destuff(char *input, char *output) {
    int count = 0;
    for (int i = 0, j = 0; input[i]; i++) {
        if (input[i] == '1' && ++count == 5) {
            i++; // Skip the stuffed '0'
            count = 0;
        } else {
            output[j++] = input[i];
            if (input[i] == '0') count = 0;
        }
    }
}

int main() {
    char input[] = "111111001111101111110";
    char stuffed[50], destuffed[50];
    
    stuff(input, stuffed);
    printf("Original: %s\nStuffed: %s\n", input, stuffed);
    
    destuff(stuffed, destuffed);
    printf("Destuffed: %s\n", destuffed);
    
    return 0;
}