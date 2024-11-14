#include <stdio.h>
#include <string.h>
int main(){
  char input[100],output[100] = "";
  printf("Enter your words: \n");
  fgets(input ,sizeof(input) ,stdin);
  input[strcspn(input, "\n")]='\0';
  char *word = strtok(input," ");
  char temp[100][100];
  int pnt_cnt = 0;
  while(word != NULL){
    strcpy(temp[pnt_cnt], word);
    pnt_cnt++;
    word = strtok(NULL, " ");
  }
  for(int i = pnt_cnt - 1; i >= 0; i--){
    strcat(output, temp[i]);
    if(i>0){
        strcat(output, " ");
    }
  }
  printf("Your words in reverse order: \n%s", output);
  return 0;
}
