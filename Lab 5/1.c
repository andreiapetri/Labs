#include <stdio.h>
void copy_array(int *src, int *dest, int size){
    for (int i = 0; i < size; i++){
        dest[i] = src[i];
    }
}
int main(){
    int source[] = {1, 2, 3, 4, 5};
    int destination[5];
    copy_array(source, destination, 5);
    printf("Copied array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", destination[i]);
    }
    printf("\n");
    return 0;
}
