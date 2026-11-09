

#include <stdio.h>

int main(void)
{
    float basicSalary;
    float housing;
    float transport;
    float tax;
    float grossSalary;
    float netSalary;

    printf("====================================\n");
    printf("     EMPLOYEE SALARY CALCULATOR\n");
    printf("====================================\n");

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\n--- SALARY REPORT ---\n");
    printf("Gross Salary: N$%.2f\n", grossSalary);
    printf("Net Salary: N$%.2f\n", netSalary);

    if (netSalary >= 20000) {
        printf("Income Status: High Income\n");
    }
    else {
        printf("Income Status: Standard Income\n");
    }

    return 0;
}
