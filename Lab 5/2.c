#include <stdio.h>
void copy_array(int *src, int *dest, int size){
    for (int i = 0; i < size; i++){
        dest[i] = src[i]; // Potential out-of-bounds error if size > dest size
    }
}
int main() {
    int source[] = {1, 2, 3, 4, 5};
    int destination[3]; // Destination size is smaller
    copy_array(source, destination, 5); // Deliberately incorrect size
    printf("Destination array (may crash or show undefined behavior): ");
    for (int i = 0; i < 5; i++){
        printf("%d ", destination[i]);
    }
    printf("\n");
    return 0;
}
