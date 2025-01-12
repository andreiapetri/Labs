#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void dectohex(int n);
void reverse(const char *str, int index);
void dectohex(int n){
    int hex=0;
    if(!n){
        return;
    }
    else{
        hex=n%16;
        dectohex(n/16);
    }
    if(hex>9){
        printf("%c", 'A'+(hex-10));
    }
    else{
        printf("%d", hex);
    }
}
void reverse(const char *str, int index) {
    if (index < 0) return;
    putchar(str[index]);
    reverse(str, index - 1);
}
