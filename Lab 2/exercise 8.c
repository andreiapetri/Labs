#include <stdio.h>
#include <math.h>
double zeta(double s, int max_n) {
    double sum = 0.0;
    for (int n = 1; n <= max_n; n++) {
        sum += 1.0 / pow(n, s);
    }
    return sum;
}
int main() {
    double s;
    int max_n;
    printf("Enter the value of s (s > 1): ");
    scanf("%lf", &s);
    if (s <= 1) {
        printf("The value of s must be greater than 1.\n");
        return 1;
    }
    printf("\nApproximations of the Riemann Zeta function for s = %.2f:\n", s);
    for (max_n = 10; max_n <= 100000000; max_n *= 10) {
        double result = zeta(s, max_n);
        printf("Approximation with n = %d: Zeta(%.2f) = %.6f\n", max_n, s, result);
    }
    return 0;
}
