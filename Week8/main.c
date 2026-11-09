#include <stdio.h>
#include <string.h>

char supplierNames[5][100];
char supplierEmails[5][100];
char supplierPhones[5][30];
char supplierTowns[5][50];

int supplierCount = 0;

void displayMenu(void);
void employeeSalaryOption(void);
void vatOption(void);
void budgetOption(void);
void employeeSearchOption(void);
void supplierManagement(void);
void exitProgram(void);

void addSupplier(void);
void displaySupplier(void);
void searchSupplier(void);

float calculateSalary(float basic, float housing, float transport);
float calculateVAT(float amount);
float calculateBudget(float revenue, float expenses);

int searchEmployee(int id, int ids[], int size);

int main(void)
{
    int choice;

    do {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                employeeSalaryOption();
                break;

            case 2:
                vatOption();
                break;

            case 3:
                budgetOption();
                break;

            case 4:
                employeeSearchOption();
                break;

            case 5:
                supplierManagement();
                break;

            case 6:
                exitProgram();
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

void displayMenu(void)
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

void employeeSalaryOption(void)
{
    float basic, housing, transport;
    float grossSalary;

    printf("\n--- EMPLOYEE SALARY CALCULATION ---\n");

    printf("Enter basic salary: ");
    if (scanf("%f", &basic) != 1) return;

    printf("Enter housing allowance: ");
    if (scanf("%f", &housing) != 1) return;

    printf("Enter transport allowance: ");
    if (scanf("%f", &transport) != 1) return;

    grossSalary = calculateSalary(basic, housing, transport);

    printf("Gross Salary: N$%.2f\n", grossSalary);
}

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

void vatOption(void)
{
    float amount;
    float vat;

    printf("\n--- VAT CALCULATION ---\n");

    printf("Enter amount: ");
    if (scanf("%f", &amount) != 1) return;

    vat = calculateVAT(amount);

    printf("VAT (15%%): N$%.2f\n", vat);
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void budgetOption(void)
{
    float revenue, expenses, balance;

    printf("\n--- BUDGET CALCULATION ---\n");

    printf("Enter revenue: ");
    if (scanf("%f", &revenue) != 1) return;

    printf("Enter expenses: ");
    if (scanf("%f", &expenses) != 1) return;

    balance = calculateBudget(revenue, expenses);

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

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }

    return -1;
}

void employeeSearchOption(void)
{
    int employeeIDs[5] = {101, 102, 103, 104, 105};
    int id, position;

    printf("\n--- EMPLOYEE SEARCH ---\n");

    printf("Enter employee ID: ");
    if (scanf("%d", &id) != 1) return;

    position = searchEmployee(id, employeeIDs, 5);

    if (position != -1) {
        printf("Employee found at position %d.\n", position);
    }
    else {
        printf("Employee not found.\n");
    }
}

void supplierManagement(void)
{
    int choice;

    do {
        printf("\n====================================\n");
        printf("       SUPPLIER MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Return to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        switch (choice) {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySupplier();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}

void addSupplier(void)
{
    if (supplierCount >= 5) {
        printf("Maximum of five suppliers reached.\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    printf("Enter supplier name: ");
    if (scanf(" %99[^\n]", supplierNames[supplierCount]) != 1)
        return;

    printf("Enter supplier email: ");
    if (scanf(" %99[^\n]", supplierEmails[supplierCount]) != 1)
        return;

    printf("Enter supplier phone number: ");
    if (scanf(" %29[^\n]", supplierPhones[supplierCount]) != 1)
        return;

    printf("Enter supplier town: ");
    if (scanf(" %49[^\n]", supplierTowns[supplierCount]) != 1)
        return;

    supplierCount++;

    printf("Supplier added successfully.\n");
}

void displaySupplier(void)
{
    if (supplierCount == 0) {
        printf("No suppliers stored.\n");
        return;
    }

    printf("\n--- SUPPLIER INFORMATION ---\n");

    for (int i = 0; i < supplierCount; i++) {
        printf("\nSupplier %d\n", i + 1);
        printf("Name: %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town: %s\n", supplierTowns[i]);
    }
}

void searchSupplier(void)
{
    char searchName[100];

    printf("\n--- SUPPLIER SEARCH ---\n");
    printf("Enter supplier name to search: ");

    if (scanf(" %99[^\n]", searchName) != 1)
        return;

    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(supplierNames[i], searchName) == 0) {
            printf("\nSupplier found.\n");
            printf("Name: %s\n", supplierNames[i]);
            printf("Email: %s\n", supplierEmails[i]);
            printf("Phone: %s\n", supplierPhones[i]);
            printf("Town: %s\n", supplierTowns[i]);
            return;
        }
    }

    printf("Supplier not found.\n");
}

void exitProgram(void)
{
    printf("Goodbye.\n");
}
