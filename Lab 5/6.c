#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 5
#define MAX_LENGTH 50
int main(){
    char strings[MAX_STRINGS][MAX_LENGTH];
    char suffix[MAX_LENGTH];
    printf("Enter %d strings:\n", MAX_STRINGS);
    for (int i = 0; i < MAX_STRINGS; i++){
        printf("String %d: ", i + 1);
        scanf("%s", strings[i]);
    }
    printf("Enter a suffix: ");
    scanf("%s", suffix);
    printf("Strings with suffix:\n");
    for (int i = 0; i < MAX_STRINGS; i++){
        strcat(strings[i], suffix);
        printf("%s\n", strings[i]);
    }
    return 0;
}
