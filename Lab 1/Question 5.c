#include <stdio.h>
void add(long double num1, long double num2);
void subtract(long double num1, long double num2);
void multiply(long double num1, long double num2);
int main(){   
	long double num1, num2;
	printf("Enter a number\n");
	scanf("%Lf", &num1);
	printf("Enter another number\n");
	scanf("%Lf", &num2);
	add(num1, num2);
	subtract(num1, num2);
	multiply(num1, num2);
    
	return 0;
}

void add(long double num1, long double num2){
	printf("Sum: %Lf\n", num1 + num2);
}

void subtract(long double num1, long double num2){
	printf("Difference: %Lf\n", num1 - num2);
}

void multiply(long double num1, long double num2){
	printf("Product: %Lf\n", num1 * num2);
}
