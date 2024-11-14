#include <stdio.h>
int main(void){
    int i;
    int j;
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            int sum = i*j;
            if(i*j<10){
                printf(" ");
            }
            if(j==10 && i*j<100){
                printf(" ");
            }
            printf(" %d ",sum);
        }
        printf("\n");
    }
}
