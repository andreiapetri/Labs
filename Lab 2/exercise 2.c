#include <stdio.h>
int main(){
  float weight;
  int value;
  printf("Enter your weight in pounds: \n");
  scanf("%f", &weight);
  value = 1770.0 * weight * 14.5;
  printf("Your weight in platinum costs (decimal): %d\n", value);
  printf("Your weight in platinum costs (octal): %o\n", value);
  printf("Your weight in platinum costs (hexadecimal): %x\n", value);
  return 0;
}
