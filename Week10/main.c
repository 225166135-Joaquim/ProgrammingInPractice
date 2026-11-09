#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"
#include "storage.h"

int main(void)
{
    int choice, id;
    float basic, housing, transport;
    float amount, revenue, expenses;

    do {
        displayMenu();

        if (!readInt("Enter choice: ", &choice))
            return 1;

        switch (choice) {

            case 1:
                if (!readFloat("Basic salary: ", &basic) ||
                    !readFloat("Housing allowance: ", &housing) ||
                    !readFloat("Transport allowance: ", &transport))
                    return 1;

                displaySalaryReport(basic, housing, transport);
                break;

            case 2:
                if (!readFloat("Amount: ", &amount))
                    return 1;

                displayVATReport(amount);
                break;

            case 3:
                if (!readFloat("Revenue: ", &revenue) ||
                    !readFloat("Expenses: ", &expenses))
                    return 1;

                displayBudgetReport(revenue, expenses);
                break;

            case 4:
                if (!readInt("Employee ID to search: ", &id))
                    return 1;

                searchStoredEmployee(id);
                break;

            case 5:
                addRecord(0);
                break;

            case 6:
                addRecord(1);
                break;

            case 7:
                addRecord(2);
                break;

            case 8:
                addRecord(3);
                break;

            case 9:
                displayRecords();
                break;

            case 10:
                saveAllData();
                break;

            case 11:
                loadAllData();
                break;

            case 12:
                saveEmployeesBinary();
                break;

            case 13:
                loadEmployeesBinary();
                break;

            case 14:
                backupData();
                break;

            case 15:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 15);

    return 0;
}
