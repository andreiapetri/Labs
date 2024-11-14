#include <stdio.h>
int main(){
    float x;
    int keyICT,keyGREEN;
    float taxbracket_1=0,taxbracket_2=0,taxbracket_3=0;
    float tax=0;
    printf("Enter your income so i can calculate your tax: \n");
    scanf("%f", &x);
    float temp=x;
    printf("Are you working in the ICT industry? (if yes enter 1 , if no enter 0)\n");
    scanf("%d", &keyICT);
    printf("Are you collecting old electronic equipment for green disposal? (for yes enter 1 for no enter 0)\n");
    scanf("%d", &keyGREEN);
    if(keyGREEN==1){
        if(x>=15000){
            taxbracket_1=15000*0.18;
            x=x-15000;
        }
        else{
            taxbracket_1=x*0.18;
            x=0;
        }
        if(x>=8000){
            taxbracket_2=8000*0.20;
            x=x-8000;
        }
        else {
            taxbracket_2=x*0.25;
            x=0;
        }
        taxbracket_3=x*0.25;
        tax=taxbracket_1+taxbracket_2+taxbracket_3;
    }
    else {
        if(x>=10000){
            taxbracket_1=10000*0.18;
            x=x-10000;
        }
        else{
            taxbracket_1=x*0.18;
            x=0;
        }
        if(x>=8000){
            taxbracket_2=8000*0.20;
            x=x-8000;
        }
        else {
            taxbracket_2=x*0.25;
            x=0;
        }
        taxbracket_3=x*0.25;
        tax=taxbracket_1+taxbracket_2+taxbracket_3;
    }
    if(keyICT==1){
        tax=tax-(tax*5)/100;
    }
    float netpaycheck;
    netpaycheck = temp - tax;
    printf("Out of your %.2f$ you will be taxed for %.2f$\n", temp,tax);
    printf("Your net income will be %.2f!",netpaycheck);
    return 0;
}
