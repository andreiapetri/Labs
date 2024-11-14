#include <stdio.h>
int main(void){
    const PIN = 5996;
    int tries = 5;
    int pin;
    while(tries){
        if(tries == 5)printf("Introduce PIN code \n");
        scanf("%d",&pin);
        if(pin == PIN){
            printf("Access granted! Welcome user!");
            tries=0;
        }
        else{
            if(tries>1)printf("Wrong PIN! Try again! \n");
        }
        tries--;
    }
    if(tries==0)printf("You are now locked , try again later!");
    return 0;
}
