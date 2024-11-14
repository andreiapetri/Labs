#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 200
#define MAX_WORD_LENGTH 100
int main() {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int total_errors = 0;
    int i;
    printf("Enter a sentence: ");
    if(fgets(line,sizeof(line),stdin)){
        for(i=1;line[i]!='\0'; i++) {
        if(line[i]==' '&&line[i-1]==' '){
                printf("Warning: There are repeated spaces.\n");
                total_errors++;
                break;
            }
        }
        char *ptr=strtok(line, " \n");
        while (ptr!=NULL){
            strcpy(word, ptr);
            for(i=1;word[i]!='\0';i++){
                if(isupper(word[i])){
                    printf("Warning: '%s' has uppercase letters beyond the first character.\n", word);
                    total_errors++;
                    break;
                }
                if(ispunct(word[i])&&word[i-1]==' '){
                    printf("Warning: '%s' contains punctuation preceded by a space.\n", word);
                    total_errors++;
                    break;
                }
            }
            if(!isalpha(word[0])){
                printf("Warning: '%s' starts with a non-alphabetic character.\n", word);
                total_errors++;
            }
            if(strlen(word)>10&&strchr(word,'-')==NULL){
                printf("Warning: '%s' is longer than 10 characters and lacks a hyphen.\n", word);
                total_errors++;
            }
            ptr=strtok(NULL, " \n");
        }
    }
    if(total_errors==0) {
        printf("No errors found\n");
    }else if (total_errors==1){
        printf("1 error found\n");
    }else{
        printf("%d errors found\n", total_errors);
    }
    return 0;
}
