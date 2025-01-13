#include <stdio.h>
#define MAX 100
int main() {
    double array[MAX + 1][MAX + 1][MAX + 1];
    for (int x = 0; x <= MAX; x++){
        for (int y = 0; y <= MAX; y++){
            for (int z = 0; z <= MAX; z++){
                array[x][y][z] = x + 6 * y + 7.2 * z;
            }
        }
    }
    printf("Pre-computation complete.\n");
    return 0;
}
