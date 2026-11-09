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

                Employee *found = findEmployee(
                    employees, employeeCount, id
                );

                if (found == NULL) {
                    printf("Employee not found.\n");
                }
                else {
                    printf("Employee found: %s\n", found->name);
                    printf("Salary: N$%.2f\n", found->salary);
                }

                break;
            }

            case 19: {
                double newSalary;

                printf("\n--- UPDATE EMPLOYEE SALARY ---\n");

                if (!readInt("Enter employee ID: ", &id))
                    return 1;

                Employee *found = findEmployee(
                    employees, employeeCount, id
                );

                if (found == NULL) {
                    printf("Employee ID %d not found.\n", id);
                    break;
                }

                printf("Employee: %s\n", found->name);
                printf("Current Salary: N$%.2f\n", found->salary);

                printf("Enter new salary: ");

                if (scanf("%lf", &newSalary) != 1)
                    return 1;

                if (newSalary < 0) {
                    printf("Salary cannot be negative.\n");
                    break;
                }

                updateSalary(found, newSalary);

                printf("\n--- UPDATED EMPLOYEE ---\n");
                printf("ID: %d\n", found->id);
                printf("Name: %s\n", found->name);
                printf("Department: %s\n", found->department);
                printf("New Salary: N$%.2f\n", found->salary);

                break;
            }

            case 20:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 20);

    return 0;
}