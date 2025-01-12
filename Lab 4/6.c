#include <math.h>
#include <stdio.h>
void transform_to_ceil(double *x) {
    *x = ceil(*x);
}
void transform_to_floor(double *x) {
    *x = floor(*x);
}
void custom_ceil(double *x) {
    *x = (*x == (int)(*x)) ? *x : (int)(*x + 1);
}
void custom_floor(double *x) {
    *x = (int)(*x);
}