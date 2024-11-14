#include <stdio.h>
int main(){
	int a3 = 1000, a4 = 1000, a5 = 1000;
	int ordera3, ordera4, ordera5;
	printf("How many A3 paper packs do you want to buy, between 0 to a 1000\n");
	scanf("%d", &ordera3);
	printf("How many A4 paper packs do you want to buy, between 0 to a 1000\n");
	scanf("%d", &ordera4);
	printf("How many A5 paper packs do you want to buy, between 0 to a 1000\n");
	scanf("%d", &ordera5);
	a3 = a3 - ordera3;
	a4 = a4 - ordera4;
	a5 = a5 - ordera5;
	printf("A3 packs ordered: %d\n", ordera3);
	printf("A4 packs ordered: %d\n", ordera4);
	printf("A5 packs ordered: %d\n", ordera5);
	printf("New stock for A3: %d\n", a3);
	printf("New stock for A4: %d\n", a4);
	printf("New stock for A5: %d\n", a5);
	return 0;
}
