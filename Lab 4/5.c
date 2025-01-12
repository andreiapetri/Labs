#include <stdio.h>
#include <string.h>
void analyze_string(char *input) {
    int freq[256] = {0}, max_count = 0, length = strlen(input);
    char most_frequent = input[0];
    for (int i = 0; i < length; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            printf("Invalid input: Contains numeric characters.\n");
            return;
        }
        freq[(unsigned char)input[i]]++;
        if (freq[(unsigned char)input[i]] > max_count) {
            max_count = freq[(unsigned char)input[i]];
            most_frequent = input[i];
        }
    }
    printf("Input length: %d\n", length);
    printf("First character: %c\n", input[0]);
    printf("Most frequent character: %c\n", most_frequent);
}