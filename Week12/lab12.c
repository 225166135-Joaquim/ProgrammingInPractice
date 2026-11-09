#include <stdio.h>
#include "employees.h"

static void wrongSwap(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;

    printf("Inside wrongSwap: N$%.2f and N$%.2f\n", a, b);
}

int main(void)
{
    printf("====================================\n");
    printf("        WEEK 12 POINTER LAB\n");
    printf("====================================\n");

    int number = 10;
    int *p = &number;

    printf("\n--- PART A: POINTER WARM-UP ---\n");
    printf("Value: %d\n", number);
    printf("Address: %p\n", (void *)&number);
    printf("Value through *p: %d\n", *p);

    *p = 25;

    printf("After *p = 25, value: %d\n", number);

    double first = 15000.00;
    double second = 21000.00;

    printf("\n--- PART B: SWAP SALARIES ---\n");

    printf("Before swap:\n");
    printf("Salary 1: N$%.2f\n", first);
    printf("Salary 2: N$%.2f\n", second);

    wrongSwap(first, second);

    printf("\nAfter incorrect swap:\n");
    printf("Salary 1: N$%.2f\n", first);
    printf("Salary 2: N$%.2f\n", second);

    swapSalaries(&first, &second);

    printf("\nAfter correct swap:\n");
    printf("Salary 1: N$%.2f\n", first);
    printf("Salary 2: N$%.2f\n", second);

    double salaries[3] = {
        15000.00,
        18500.50,
        21000.75
    };

    printf("\n--- PART C: SALARY ARRAYS ---\n");

    printf("\nOriginal salaries:\n");
    displaySalaries(salaries, 3);

    printf("\nHighest Salary: N$%.2f\n",
           findHighest(salaries, 3));

    printf("Average Salary: N$%.2f\n",
           calculateAverage(salaries, 3));

    // Give each employee a 10% raise
    giveRaise(salaries, 3, 10.0);

    printf("\nSalaries after 10%% raise:\n");
    displaySalaries(salaries, 3);

    Employee staff[3] = {
        {1001, "Maria", "Finance", 18500.50},
        {1002, "Simon", "HR", 17200.00},
        {1003, "Anna", "Transport", 21000.75}
    };

    Employee *found;

    printf("\n--- EMPLOYEE POINTERS ---\n");

    found = findEmployee(staff, 3, 1002);

    if (found != NULL) {
        updateSalary(found, 19000.00);

        printf("Updated %s: N$%.2f\n",
               found->name, found->salary);

        updateSalary(found, 20000.00);

        printf("Updated %s again: N$%.2f\n",
               found->name, found->salary);
    }

    found = findEmployee(staff, 3, 9999);

    if (found == NULL) {
        printf("Employee 9999 not found.\n");
    }

    return 0;
}