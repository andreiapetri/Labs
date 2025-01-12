#include <stdio.h>
#include <stdlib.h>
long fibo(int n);
long rfibo(int n);
long fibo(int n){
    long p1=0;
    long p2=1;
    while(n){
        printf("%ld ",p1);
        long temp=p1+p2;
        p1=p2;
        p2=temp;
        n--;
    }
}
/*  
The iterative function of the fibonacci sequence is calculating each number in a sequence
and updates every variable along the way , so it is harder to read than the recursive one
which uses normal mathemtical logic. It also uses a single stackframe and has an efficiency 
of O(n), it uses less memory than than the recursive one because it s using just a single 
stackframe so it is faster when calculating larger numbers and won t overflow
*/
long rfibo(int n){
        if(n==0)return 0;
        if(n==1)return 1;
    return rfibo(n-1)+rfibo(n-2);
}
/* 
The recursive function of the fibonacci sequence is calculating in a more mathematical manner,
using the normal formula from the fibonacci sequence , has the same efficiency of O(n) as the 
iterative version but is a lot slower because it calls a stackframe for every recall of the function
and will surely have stack overflows when calculating large numbers
*/