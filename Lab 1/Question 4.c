#include <stdio.h>
void butler(char name[]);  	/* ISO/ANSI C function prototyping */
int main(void){
	printf("I will summon the butler function.\n");
	butler("Andrew");
	printf("Yes. Bring me some tea and writeable CD-ROMS.\n");
	return 0;
}
void butler(char name[]){      	  
  /* start of function definition */
	printf("You rang, %s?\n", name);
}
