#include <stdio.h>
#include <stdlib.h>
int rgcd(int n1, int n2);
/*
    I think the recursive way is harder to read in this case , but maybe for other
people it might be easier.
    It uses a stackframe for every recall of itself which makes the program unsafe
and slower when overflowing.
*/
int gcd(int n1, int n2);
/*
    Personally i think it's easier to read than the recursive one which has more
mathematical logic.
    It uses a single stackframe which makes the code more stable and faster than
the recursive one.
*/
int rgcd(int n1, int n2){
    if(n1==0 || n2==0)return 1;
    if(n1!=n2 && n1>n2){
        rgcd(n1-n2, n2);
    }
    else if(n1!=n2 && n2>n1){
        rgcd(n1, n2-n1);
    }
    else if(n1==n2)return n1;
}
int gcd(int n1, int n2){
    if(n1<n2){
        int aux=n1;
        n1=n2;
        n2=aux;
    }
    while(n1!=n2){
        if(n1>n2){
            n1=n1-n2;
        }
        else if(n1<n2){
            n2=n2-n1;
        }

    }
    return n1;
}
