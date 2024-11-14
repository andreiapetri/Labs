#include <stdio.h>
#include <stdlib.h>
int main(){
    int input;
    printf("Enter your ASCII reference number:");
    scanf("%d", &input);
    printf("Your corresponding charracter is: %c\n", (char)input);
    return 0;
}
