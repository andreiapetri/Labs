#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 100
int main() {
    char word[MAX_WORD_LENGTH];
    int total_errors = 0;
    int i;
    printf("Enter a sentence: ");

    while (scanf("%s", word) == 1) {
        int err_upper=0,err_alfabetic=0,err_lungime=0;
        for (i = 1; word[i] != '\0'; i++) {
            if (isupper(word[i])) {
                err_upper=1;
                break;
            }
        }
        if(err_upper){
            printf("Warning: '%s' has uppercase letters beyond the first character.\n", word);
            total_errors++;
        }
        if(!isalpha(word[0])){
            err_alfabetic=1;
            printf("Warning: '%s' starts with a non-alphabetic character.\n", word);
            total_errors++;
        }
        if(strlen(word)>10&&strchr(word,'-')==NULL){
            err_lungime=1;
            printf("Warning: '%s' is longer than 10 characters and lacks a hyphen.\n", word);
            total_errors++;
        }
    }
    if (total_errors == 0) {
        printf("No errors found\n");
    } else if (total_errors == 1) {
        printf("1 error found\n");
    } else {
        printf("%d errors found\n", total_errors);
    }
    return 0;
}
