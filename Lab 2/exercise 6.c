#include <stdio.h>
#include <string.h>

#define ENTRIES 10
#define DLR_TO_EUR 0.93

int main() {
    double userDollars[11];
    for(int i=1; i<= ENTRIES; i++){
        printf("\nInput User#%d dollars to convert in euro:\n",i);
        scanf("%lf", &userDollars[i]);
    }
    for(int i=1;i<=ENTRIES;i++){
        userDollars[i]*=DLR_TO_EUR;
        printf("user %d day conversion: %.2f\n",i,userDollars[i]);
    }
    return 0;
}
