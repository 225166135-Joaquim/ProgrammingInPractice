#include <stdio.h>
#include <string.h>

int main(void)
{
    float salaries[50];
    float budgets[10];
    char registrations[20][20];

    float totalSalary = 0.0f;
    float averageSalary;
    float highestSalary, lowestSalary;
    float searchSalary;

    float totalBudget = 0.0f;
    float averageBudget;
    float temp;

    char searchRegistration[20];
    int found;

    printf("PART A - EMPLOYEE SALARIES\n");

    for (int i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);

        if (scanf("%f", &salaries[i]) != 1) {
            printf("Invalid salary input.\n");
            return 1;
        }

        totalSalary += salaries[i];
    }

    highestSalary = salaries[0];
    lowestSalary = salaries[0];

    for (int i = 1; i < 50; i++) {
        if (salaries[i] > highestSalary) {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary) {
            lowestSalary = salaries[i];
        }
    }

    averageSalary = totalSalary / 50;

    printf("\nEMPLOYEE SALARIES\n");

    for (int i = 0; i < 50; i++) {
        printf("Employee %d: N$%.2f\n",
               i + 1, salaries[i]);
    }

    printf("\nAverage Salary: N$%.2f\n", averageSalary);
    printf("Highest Salary: N$%.2f\n", highestSalary);
    printf("Lowest Salary: N$%.2f\n", lowestSalary);

    printf("\nEnter a salary to search for: ");

    if (scanf("%f", &searchSalary) != 1) {
        printf("Invalid search input.\n");
        return 1;
    }

    found = 0;

    for (int i = 0; i < 50; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary found for employee %d.\n", i + 1);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Salary not found.\n");
    }

    printf("\nPART B - DEPARTMENT BUDGETS\n");

    for (int i = 0; i < 10; i++) {
        printf("Enter budget for department %d: ", i + 1);

        if (scanf("%f", &budgets[i]) != 1) {
            printf("Invalid budget input.\n");
            return 1;
        }

        totalBudget += budgets[i];
    }

    averageBudget = totalBudget / 10;

    printf("\nDEPARTMENT BUDGETS\n");

    for (int i = 0; i < 10; i++) {
        printf("Department %d: N$%.2f\n",
               i + 1, budgets[i]);
    }

    printf("\nTotal Budget: N$%.2f\n", totalBudget);
    printf("Average Budget: N$%.2f\n", averageBudget);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBUDGETS SORTED FROM LOWEST TO HIGHEST\n");

    for (int i = 0; i < 10; i++) {
        printf("N$%.2f\n", budgets[i]);
    }

    printf("\nPART C - VEHICLE REGISTRATION NUMBERS\n");

    for (int i = 0; i < 20; i++) {
        printf("Enter registration number for vehicle %d: ",
               i + 1);

        if (scanf("%19s", registrations[i]) != 1) {
            printf("Invalid registration input.\n");
            return 1;
        }
    }

    printf("\nVEHICLE REGISTRATION NUMBERS\n");

    for (int i = 0; i < 20; i++) {
        printf("Vehicle %d: %s\n",
               i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");

    if (scanf("%19s", searchRegistration) != 1) {
        printf("Invalid search input.\n");
        return 1;
    }

    found = 0;

    for (int i = 0; i < 20; i++) {
        if (strcmp(registrations[i], searchRegistration) == 0) {
            printf("Registration found for vehicle %d.\n",
                   i + 1);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Registration number not found.\n");
    }

    return 0;
}
