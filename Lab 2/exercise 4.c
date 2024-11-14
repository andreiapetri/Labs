#include <stdio.h>
#include <string.h>
#define MAX_ENTRIES 10
#define MAX_NAME_LENGTH 10
void inputNameTxt() {
    printf("Name: ");
}
void inputSurnameTxt() {
    printf("Surname: ");
}
void inputAgeTxt() {
    printf("Age: ");
}
void inputSalaryTxt() {
    printf("Monthly Salary: ");
}
void inputDecimalPntsTxt() {
    printf("\nEnter the number of decimal places for salary display (0-2): \n");
}
void inputIdTxt(int c) {
    printf("\n Enter Employee #%d details\n", c);
}
int main() {
    char name[MAX_ENTRIES][MAX_NAME_LENGTH + 1];
    char surname[MAX_ENTRIES][MAX_NAME_LENGTH + 1];
    int age[MAX_ENTRIES];
    float salary[MAX_ENTRIES];
    int counter = 1;
    int entries = 0;
    double total_salary = 0.0;
    int precision;
    inputDecimalPntsTxt();
    scanf("%d", &precision);
    if (precision < 0 || precision > 2) precision = 2;
    while (entries < MAX_ENTRIES) {
        inputIdTxt(counter);
        getchar();
        inputNameTxt();
        fgets(name[entries], sizeof(name[entries]), stdin);
        name[entries][strcspn(name[entries], "\n")] = '\0';
        if (strlen(name[entries]) > MAX_NAME_LENGTH) {
            name[entries][MAX_NAME_LENGTH] = '\0';
        }
        inputSurnameTxt();
        fgets(surname[entries], sizeof(surname[entries]), stdin);
        surname[entries][strcspn(surname[entries], "\n")] = '\0';
        if (strlen(surname[entries]) > MAX_NAME_LENGTH) {
            surname[entries][MAX_NAME_LENGTH] = '\0';
        }
        inputAgeTxt();
        scanf("%d", &age[entries]);
        inputSalaryTxt();
        scanf("%f", &salary[entries]);
        double yearly_salary = salary[entries] * 13;
        total_salary += yearly_salary;
        //TABLE WITH EVERYTHING
        if ((entries + 1) % 5 == 0 || (entries + 1) == MAX_ENTRIES) {
            printf("\n%-4s %-11s %-11s %-4s %-10s %-10s\n", "No.", "Name", "Surname", "Age", "Monthly", "Yearly");
            printf("---------------------------------------------------------\n");
            for (int i = entries - (entries % 5); i <= entries; i++) {
                printf("%-4d %-11s %-11s %-4d %.*f %.*f\n", i + 1, name[i], surname[i], age[i],
                       precision, salary[i], precision, salary[i] * 13);
            }
        }
        entries++;
        counter++;
    }
    double average_salary = total_salary / MAX_ENTRIES;
    printf("\nAverage Yearly Salary for all entries: %.*f\n", precision, average_salary);
    return 0;
}
