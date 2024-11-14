#include <stdio.h>
int main(void){
    long n=1;
    int s;
    int i;
    printf("Introduce number to factorize: ");
    scanf("%d", &s);
    for(i=1;i<=s;i++){
        n=n*i;
    }
    printf("Factorial of %d is equal to %ld",s,n);
    return 0;
}
