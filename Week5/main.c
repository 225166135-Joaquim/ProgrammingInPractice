
#include <stdio.h>

int main(void)
{
    float salary;
    float total = 0.0f;
    float average;
    float highest = 0.0f;
    float lowest = 0.0f;

    printf("MUNICIPAL EMPLOYEE SALARY DATABASE\n\n");

    for (int i = 1; i <= 50; i++) {
        printf("Enter salary for employee %d: ", i);

        if (scanf("%f", &salary) != 1) {
            printf("Invalid salary input.\n");
            return 1;
        }

        total += salary;
\
        if (i == 1) {
            highest = salary;
            lowest = salary;
        }
        else {
            if (salary > highest) {
                highest = salary;
            }

            if (salary < lowest) {
                lowest = salary;
            }
        }
    }

    average = total / 50;

    printf("\nSALARY REPORT\n");
    printf("Total Salary: N$%.2f\n", total);
    printf("Average Salary: N$%.2f\n", average);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);

    return 0;
}
