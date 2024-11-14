#include <stdio.h>
#include <string.h>
unsigned long long factorial(int a){
    unsigned long long result = 1;
    for(int i = 1;i<= a; i++){
        result*=i;
    }
    return result;
}
int main() {
    int number;
    printf("Enter your number: \n");
    scanf("%d", &number);
    if(number < 0){
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }
    unsigned long long fact = factorial(number);
    printf("%d! is equal to: %llu\n", number, fact);
    return 0;
}
