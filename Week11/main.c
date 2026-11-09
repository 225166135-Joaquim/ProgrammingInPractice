
#include <stdio.h>
#include "records.h"
#include "storage.h"
#include "utilities.h"
#include "reports.h"
#include "employees.h"

int main(void)
{
    int choice;
    int id;
    int ids[MAX_RECORDS];

    float basic, housing, transport;
    float amount, revenue, expenses;

    do {
        displayMenu();

        if (!readInt("Enter choice: ", &choice))
            return 1;

        switch (choice) {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                addSupplier();
                break;

            case 4:
                displaySuppliers();
                break;

            case 5:
                addAsset();
                break;

            case 6:
                displayAssets();
                break;

            case 7:
                addBudget();
                break;

            case 8:
                displayBudgets();
                break;

            case 9:
                addProject();
                break;

            case 10:
                displayProjects();
                break;

            case 11:
                saveTextData();
                break;

            case 12:
                loadTextData();
                break;

            case 13:
                saveEmployeesBinary();
                break;

            case 14:
                loadEmployeesBinary();
                break;

            case 15:
                if (!readFloat("Basic salary: ", &basic) ||
                    !readFloat("Housing allowance: ", &housing) ||
                    !readFloat("Transport allowance: ", &transport))
                    return 1;

                displaySalaryReport(basic, housing, transport);
                break;

            case 16:
                if (!readFloat("Amount: ", &amount))
                    return 1;

                displayVATReport(amount);
                break;

            case 17:
                if (!readFloat("Revenue: ", &revenue) ||
                    !readFloat("Expenses: ", &expenses))
                    return 1;

                displayBudgetReport(revenue, expenses);
                break;

            case 18: {
                if (!readInt("Employee ID: ", &id))
                    return 1;

                for (int i = 0; i < employeeCount; i++) {
                    ids[i] = employees[i].id;
                }

                int position = searchEmployee(
                    id, ids, employeeCount
                );

                if (position < 0)
                    printf("Employee not found.\n");
                else
                    printf("Employee found: %s\n",
                           employees[position].name);

                break;
            }

            case 19:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 19);

    return 0;
}