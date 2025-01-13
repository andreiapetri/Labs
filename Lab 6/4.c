#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {char title[40];char author[40];float price;} Book;  // Define Book structure
typedef struct {long offset;} Index;  // Define Index structure
int compare_by_title_asc(Book a, Book b) {return strcmp(a.title, b.title);}  // Comparator for title ascending
int compare_by_title_desc(Book a, Book b) {return strcmp(b.title, a.title);}  // Comparator for title descending
int compare_by_author_asc(Book a, Book b) {return strcmp(a.author, b.author);}  // Comparator for author ascending
int compare_by_author_desc(Book a, Book b) {return strcmp(b.author, a.author);}  // Comparator for author descending
int compare_by_price_asc(Book a, Book b) {return (a.price > b.price) - (a.price < b.price);}  // Comparator for price ascending
int compare_by_price_desc(Book a, Book b) {return (a.price < b.price) - (a.price > b.price);}  // Comparator for price descending
void selection_sort(Index *indexes, int count, FILE *fp, int (*comparator)(Book, Book)) {  
  for (int i = 0; i < count - 1; i++) { 
    int min_or_max = i;
    for (int j = i + 1; j < count; j++) { 
      fseek(fp, indexes[j].offset, SEEK_SET); 
      Book book1; fread(&book1, sizeof(Book), 1, fp); 
      fseek(fp, indexes[min_or_max].offset, SEEK_SET); 
      Book book2; fread(&book2, sizeof(Book), 1, fp); 
      if (comparator(book1, book2) < 0) min_or_max = j; 
    } 
    if (min_or_max != i) { 
      Index temp = indexes[i]; 
      indexes[i] = indexes[min_or_max]; 
      indexes[min_or_max] = temp; 
    } 
  }
}  // Sort indexes
void display_books(FILE *fp, Index *indexes, int count) {  
  for (int i = 0; i < count; i++) { 
    fseek(fp, indexes[i].offset, SEEK_SET); 
    Book book; fread(&book, sizeof(Book), 1, fp); 
    printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n\n", book.title, book.author, book.price); 
  } 
}  // Display book details
void save_indexes(FILE *index_file, Index *indexes, int count) {  
  fwrite(indexes, sizeof(Index), count, index_file); 
}  // Write indexes to file
void load_indexes(FILE *index_file, Index *indexes, int *count) {  
  fseek(index_file, 0, SEEK_END); 
  long file_size = ftell(index_file); 
  *count = file_size / sizeof(Index); 
  fseek(index_file, 0, SEEK_SET); 
  fread(indexes, sizeof(Index), *count, index_file); 
}  // Read indexes from file
int main(void) {  
  Book books[] = {{"The C Programming Language", "Kernighan & Ritchie", 29.99}, 
                  {"Clean Code", "Robert C. Martin", 24.99}, 
                  {"The Pragmatic Programmer", "Andrew Hunt", 39.99}};  // Initialize books array
  int book_count = sizeof(books) / sizeof(books[0]);  // Calculate number of books
  FILE *fp = fopen("book.dat", "rb+");  // Open file for reading and writing
  if (!fp) {  
    fp = fopen("book.dat", "wb"); 
    if (!fp) {perror("Unable to open file for writing"); return 1;}  // Error handling
    for (int i = 0; i < book_count; i++) fwrite(&books[i], sizeof(Book), 1, fp);  // Write books to file
    fclose(fp); 
  }  
  FILE *index_file = fopen("index.dat", "rb+");  // Open index file for reading and writing
  if (!index_file) {  
    index_file = fopen("index.dat", "wb"); 
    if (!index_file) {perror("Unable to open index file for writing"); return 1;}  // Error handling
  }
  Index indexes[book_count];  // Array to store indexes of books
  int index_count = 0;
  load_indexes(index_file, indexes, &index_count);  // Load indexes from file
  fseek(fp, 0, SEEK_END);  // Move to the end of the file
  for (int i = 0; i < book_count; i++) {  // Add new books to the file
    fwrite(&books[i], sizeof(Book), 1, fp);  // Write new books to file
    indexes[index_count].offset = (index_count++) * sizeof(Book);  // Store file offset in index
  }
  save_indexes(index_file, indexes, index_count);  // Save indexes to file
  fclose(index_file);  // Close index file
  fp = fopen("book.dat", "rb");  // Reopen book file for reading
  if (!fp) {perror("Unable to open file for reading"); return 1;}  // Error handling
  printf("Books sorted by title (ascending):\n");  // Print sorted by title ascending
  selection_sort(indexes, index_count, fp, compare_by_title_asc);  // Sort by title ascending
  display_books(fp, indexes, index_count);  // Display books
  printf("Books sorted by title (descending):\n");  // Print sorted by title descending
  selection_sort(indexes, index_count, fp, compare_by_title_desc);  // Sort by title descending
  display_books(fp, indexes, index_count);  // Display books
  printf("Books sorted by author (ascending):\n");  // Print sorted by author ascending
  selection_sort(indexes, index_count, fp, compare_by_author_asc);  // Sort by author ascending
  display_books(fp, indexes, index_count);  // Display books
  printf("Books sorted by author (descending):\n");  // Print sorted by author descending
  selection_sort(indexes, index_count, fp, compare_by_author_desc);  // Sort by author descending
  display_books(fp, indexes, index_count);  // Display books
  printf("Books sorted by price (ascending):\n");  // Print sorted by price ascending
  selection_sort(indexes, index_count, fp, compare_by_price_asc);  // Sort by price ascending
  display_books(fp, indexes, index_count);  // Display books
  printf("Books sorted by price (descending):\n");  // Print sorted by price descending
  selection_sort(indexes, index_count, fp, compare_by_price_desc);  // Sort by price descending
  display_books(fp, indexes, index_count);  // Display books
  fclose(fp);  // Close book file
  return 0; 
}
