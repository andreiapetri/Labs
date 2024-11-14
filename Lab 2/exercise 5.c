#include <stdio.h>
#include <string.h>

#define ENTRIES 10
#define WEEK 7

int main() {
    int userDays[11];
    for(int i=1; i<= ENTRIES; i++){
        printf("\nInput days for user #%d:\n",i);
        scanf("%d", &userDays[i]);
    }
    for(int i=1;i<=ENTRIES;i++){
    int weeks=0;
        if(userDays[i]>=WEEK){
            while(userDays[i]>=WEEK){
                userDays[i]-=WEEK;
                weeks++;
            }
        }
    printf("user %d day conversion: %d week(s) and %d day(s)\n",i,weeks,userDays[i]);
    }
    return 0;
}
