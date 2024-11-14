#include <stdio.h>
#include <stdlib.h>
#define MIN_RANGE -150.0
#define MAX_RANGE 100.0
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
int main() {
    FILE *input_fp=fopen(INPUT_FILE, "r");
    FILE *output_fp=fopen(OUTPUT_FILE, "w");
    char input_line[100];
    if(!input_fp || !output_fp){
        return 1;
    }
    while (fscanf(input_fp, "%s", input_line)==1){
        char *end_pointer;
        double number = strtod(input_line, &end_pointer);
        if(number>=MIN_RANGE && number<=MAX_RANGE && *end_pointer=='\0'){
            fprintf(output_fp, "%.1f\n", number);
        }
    }
    fclose(input_fp);
    fclose(output_fp);
    return 0;
}
