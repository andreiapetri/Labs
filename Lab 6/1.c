#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_FILE_SIZE 100000
int is_word_boundary(char c) {
    return isspace(c) || ispunct(c) || c == '\0';
}
void replace_word(const char *content, const char *search, const char *replace, char *output) {
    const char *current = content;
    char *out_ptr = output;
    size_t search_len = strlen(search);
    size_t replace_len = strlen(replace);
    while (*current) {
        if (strncmp(current, search, search_len) == 0 &&
            (current == content || is_word_boundary(*(current - 1))) &&
            is_word_boundary(*(current + search_len))) {
            strncpy(out_ptr, replace, replace_len);
            out_ptr += replace_len;
            current += search_len;
        } else {
            *out_ptr++ = *current++;
        }
    }
    *out_ptr = '\0';
}
int main() {
    char filename[256], search[256], replace[256];
    printf("Enter the filename: ");
    scanf("%255s", filename);
    printf("Enter the word to search for: ");
    scanf("%255s", search);
    printf("Enter the replacement word: ");
    scanf("%255s", replace);
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    char *content = malloc(MAX_FILE_SIZE);
    if (!content) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }
    size_t content_len = fread(content, 1, MAX_FILE_SIZE - 1, file);
    content[content_len] = '\0';
    fclose(file);
    char *output = malloc(content_len + strlen(replace) * 10);
    if (!output) {
        perror("Memory allocation failed");
        free(content);
        return 1;
    }
    replace_word(content, search, replace, output);
    file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        free(content);
        free(output);
        return 1;
    }
    fwrite(output, 1, strlen(output), file);
    fclose(file);
    printf("Replacement completed.\n");
    free(content);
    free(output);
    return 0;
}
