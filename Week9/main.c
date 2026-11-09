#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void)
{
    int choice;
    int id;
    int position;
    int employeeIDs[5] = {101, 102, 103, 104, 105};

    float basic, housing, transport;
    float amount, revenue, expenses;

    do {
        displayMenu();

        if (!readInt("Enter choice: ", &choice))
            return 1;

        switch (choice) {
            case 1:
                if (!readFloat("Enter basic salary: ", &basic))
                    return 1;

                if (!readFloat("Enter housing allowance: ", &housing))
                    return 1;

                if (!readFloat("Enter transport allowance: ", &transport))
                    return 1;

                displaySalaryReport(basic, housing, transport);
                break;

            case 2:
                if (!readFloat("Enter amount: ", &amount))
                    return 1;

                displayVATReport(amount);
                break;

            case 3:
                if (!readFloat("Enter revenue: ", &revenue))
                    return 1;

                if (!readFloat("Enter expenses: ", &expenses))
                    return 1;

                displayBudgetReport(revenue, expenses);
                break;

            case 4:
                if (!readInt("Enter employee ID: ", &id))
                    return 1;

                position = searchEmployee(id, employeeIDs, 5);

                if (position >= 0) {
                    printf("Employee found at position %d.\n",
                           position);
                }
                else {
                    printf("Employee not found.\n");
                }
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
