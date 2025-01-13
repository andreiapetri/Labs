#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_EMPLOYEES 5
typedef struct{
    char name[50];
    char surname[50];
    int id;
    double salary;
} Employee;
int compare_by_id(const void *a, const void *b){
    return ((Employee *)a)->id - ((Employee *)b)->id;
}
int compare_by_surname(const void *a, const void *b){
    return strcmp(((Employee *)a)->surname, ((Employee *)b)->surname);
}
int main(){
    Employee employees[MAX_EMPLOYEES] = {
        {"John", "Doe", 102, 5000.0},
        {"Jane", "Smith", 101, 5500.0},
        {"Alice", "Brown", 103, 5200.0},
        {"Bob", "White", 100, 4800.0},
        {"Charlie", "Davis", 104, 4700.0}
    };
    printf("Employees sorted by ID:\n");
    qsort(employees, MAX_EMPLOYEES, sizeof(Employee), compare_by_id);
    for (int i = 0; i < MAX_EMPLOYEES; i++){
        printf("%d: %s %s\n", employees[i].id, employees[i].name, employees[i].surname);
    }
    printf("\nEmployees sorted by surname:\n");
    qsort(employees, MAX_EMPLOYEES, sizeof(Employee), compare_by_surname);
    for (int i = 0; i < MAX_EMPLOYEES; i++){
        printf("%s: %s\n", employees[i].surname, employees[i].name);
    }
    return 0;
}
