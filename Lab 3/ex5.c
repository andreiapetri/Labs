#include <stdio.h>
int main(){
    int v[20],fv[101]={0};
    int i,count=0,sum=0,median,index=0,maxim=0;
    float average = 0.0;
    printf("Enter up to 20 numbers between 1 and 100  (enter -1 to stop):\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &v[i]);
        if (v[i] == -1) break;
        count++;
        sum += v[i];
    }
    if (count % 2 == 0){
        median = (v[count/2-1]+v[count/2])/2;
    } else {
        median = v[count/2];
    }
    average = sum / count;
    for (i = 0; i < count; i++){
        fv[v[i]]++;
    }
    for (i = 1; i <= 100; i++){
        if (fv[i] > maxim) {
            maxim = fv[i];
            index = i;
        }
    }
    printf("MEAN = %.2f\n", average);
    printf("MEDIAN = %d\n", median);
    printf("MODE = %d\n", index);
    return 0;
}
