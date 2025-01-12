#include <stdio.h>
#include <stdlib.h>
long fact(int n);
long rfact(int n);
    /*  
    Iterative function has less chances to cause stack overflows because it uses a single stackframe per call
so it's number of stackframes possible to use is 1                                                                      
    */
    /*  
    Recursive function on the other hand , has higher chances of stack overflows because it creates another stackframe
everytime it calls itself , so it's number of stackframes will be(n+1)                                                  
    */
    /*
    In conlcusion , the iterative function uses 1 stackframe and the recursive one uses n+1 stackframes
    */
long fact(int n) {
    long ans;
    for (ans = 1; n > 1; n--)
        ans *= n;
    return ans;
}
long rfact(int n) {
    long ans;
    if (n > 0)
        ans = n * rfact(n - 1);
    else
        ans = 1;
    return ans;
}
