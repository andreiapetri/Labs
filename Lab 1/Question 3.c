#include <stdio.h>
int main(void){
	int dogs, cats;
	printf("How many dogs do you have?\n");
	scanf("%d", &dogs);
	printf("So you have %d dog(s)!\n", dogs);
	printf("How many cats do you have?\n");
	scanf("%d", &cats);
	printf("So you have %d pet(s)!\n", cats+dogs);
	return 0;
}
