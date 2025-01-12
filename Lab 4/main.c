#include <stdio.h>
#include <string.h>
#include "utils.h"
void menu() {
    printf("Choose an option:\n");
    printf("1. Factorial (Iterative & Recursive)\n");
    printf("2. Fibonacci (Iterative & Recursive)\n");
    printf("3. GCD (Iterative & Recursive)\n");
    printf("4. Decimal to Hexadecimal\n");
    printf("5. Reverse String\n");
    printf("6. Analyze String\n");
    printf("7. Ceil and Floor Transformations\n");
    printf("0. Exit\n");
}
int main() {
    int choice;
    char str[100];
    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Iterative Factorial: %ld\n", fact(n));
                printf("Recursive Factorial: %ld\n", rfact(n));
                break;
            }
            case 2: {
                int n;
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("Iterative Fibonacci: %ld\n", fibo(n));
                printf("Recursive Fibonacci: %ld\n", rfibo(n));
                break;
            }
            case 3: {
                int x, y;
                printf("Enter two numbers (x > y): ");
                scanf("%d %d", &x, &y);
                printf("Iterative GCD: %d\n", gcd(x, y));
                printf("Recursive GCD: %d\n", rgcd(x, y));
                break;
            }
            case 4: {
                int n;
                printf("Enter a decimal number: ");
                scanf("%d", &n);
                printf("Hexadecimal: ");
                dectohex(n);
                printf("\n");
                break;
            }
             case 5: {
                char str[100];
                printf("Enter a string: ");
                scanf("%s", str);
                reverse(str, strlen(str) - 1);
                printf("\n");
                break;
            }
            case 6: {
                char input[100];
                printf("Enter a string: ");
                scanf("%s", input);
                analyze_string(input);
                break;
            }
            case 7: {
                double x;
                printf("Enter a real number: ");
                scanf("%lf", &x);
                printf("Using math.h:\n");
                transform_to_ceil(&x);
                printf("Ceil: %.2f\n", x);
                transform_to_floor(&x);
                printf("Floor: %.2f\n", x);
                break;
            }
        }
    } while (choice != 0);
    return 0;
}
