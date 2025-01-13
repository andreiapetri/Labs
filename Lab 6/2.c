#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int is_word_boundary(char c) {
    return isspace(c) || ispunct(c) || c == '\0';
}
void process_file(const char *filename, const char *search, const char *replace) {
    FILE *input_file = fopen(filename, "r");
    if (!input_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    FILE *temp_file = tmpfile();
    if (!temp_file) {
        perror("Error creating temporary file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }
    size_t search_len = strlen(search), replace_len = strlen(replace);
    char buffer[1024], word[256];
    while (fgets(buffer, sizeof(buffer), input_file)) {
        char *start = buffer, *current;
        while ((current = strstr(start, search))) {
            if ((current == buffer || is_word_boundary(*(current - 1))) &&
                is_word_boundary(*(current + search_len))) {
                fwrite(start, 1, current - start, temp_file);
                fwrite(replace, 1, replace_len, temp_file);
                start = current + search_len;
            } else {
                fwrite(start, 1, current - start + 1, temp_file);
                start = current + 1;
            }
        }
        fwrite(start, 1, strlen(start), temp_file);
    }
    fclose(input_file);
    FILE *output_file = fopen(filename, "w");
    if (!output_file) {
        perror("Error opening file for writing");
        fclose(temp_file);
        exit(EXIT_FAILURE);
    }
    rewind(temp_file);
    while (fgets(buffer, sizeof(buffer), temp_file)) {
        fputs(buffer, output_file);
    }
    fclose(temp_file);
    fclose(output_file);
    printf("Replacement completed.\n");
}
int main() {
    char filename[256], search[256], replace[256];
    printf("Enter the filename: ");
    scanf("%255s", filename);
    printf("Enter the word to search for: ");
    scanf("%255s", search);
    printf("Enter the replacement word: ");
    scanf("%255s", replace);
    process_file(filename, search, replace);
    return 0;
}
