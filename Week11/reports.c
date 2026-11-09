
#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void displaySalaryReport(float basic, float housing, float transport)
{
    printf("\n--- EMPLOYEE SALARY REPORT ---\n");

    printf("Gross Salary: N$%.2f\n",
           calculateSalary(basic, housing, transport));
}

void displayVATReport(float amount)
{
    printf("\n--- VAT REPORT ---\n");

    printf("VAT (15%%): N$%.2f\n",
           calculateVAT(amount));
}

void displayBudgetReport(float revenue, float expenses)
{
    float balance = calculateBudget(revenue, expenses);

    printf("\n--- BUDGET REPORT ---\n");
    printf("Budget Balance: N$%.2f\n", balance);

    if (balance > 0) {
        printf("Status: SURPLUS\n");
    }
    else if (balance < 0) {
        printf("Status: DEFICIT\n");
    }
    else {
        printf("Status: BALANCED\n");
    }
}
