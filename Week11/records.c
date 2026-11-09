#include <stdio.h>
#include <string.h>
#include "records.h"
#include "utilities.h"

Employee employees[MAX_RECORDS];
Supplier suppliers[MAX_RECORDS];
Asset assets[MAX_RECORDS];
Budget budgets[MAX_RECORDS];
Project projects[MAX_RECORDS];

int employeeCount = 0;
int supplierCount = 0;
int assetCount = 0;
int budgetCount = 0;
int projectCount = 0;

static int readText(const char *prompt, char *text, size_t capacity)
{
    char format[32];

    printf("%s", prompt);
    snprintf(format, sizeof format,
             " %%%zu[^\n]", capacity - 1);

    if (scanf(format, text) != 1)
        return 0;

    if (strchr(text, '|') != NULL) {
        printf("The | character is not allowed.\n");
        return 0;
    }

    return 1;
}

static int readDate(const char *label, Date *date)
{
    printf("%s\n", label);

    if (!readInt("Day: ", &date->day) ||
        !readInt("Month: ", &date->month) ||
        !readInt("Year: ", &date->year))
        return 0;

    if (date->day < 1 || date->day > 31 ||
        date->month < 1 || date->month > 12 ||
        date->year < 1) {
        printf("Invalid date.\n");
        return 0;
    }

    return 1;
}

static int readDouble(const char *prompt, double *value)
{
    printf("%s", prompt);

    if (scanf("%lf", value) != 1) {
        printf("Invalid number.\n");
        return 0;
    }

    return 1;
}

void addEmployee(void)
{
    if (employeeCount == MAX_RECORDS) {
        printf("Employee storage is full.\n");
        return;
    }

    Employee e;

    printf("\n--- ADD EMPLOYEE ---\n");

    if (!readInt("Employee ID: ", &e.id) ||
        !readText("Name: ", e.name, sizeof e.name) ||
        !readText("Department: ", e.department,
                  sizeof e.department) ||
        !readDouble("Salary: ", &e.salary))
        return;

    employees[employeeCount] = e;
    employeeCount++;

    printf("Employee added successfully.\n");
}

void displayEmployees(void)
{
    printf("\n--- EMPLOYEE RECORDS ---\n");

    printf("%-8s %-29s %-19s %12s\n",
           "ID", "Name", "Department", "Salary");

    for (int i = 0; i < employeeCount; i++) {
        printf("%-8d %-29s %-19s %12.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }

    printf("Total employees: %d\n", employeeCount);
}

void addSupplier(void)
{
    if (supplierCount == MAX_RECORDS) {
        printf("Supplier storage is full.\n");
        return;
    }

    Supplier s;

    printf("\n--- ADD SUPPLIER ---\n");

    if (!readInt("Supplier ID: ", &s.id) ||
        !readText("Name: ", s.name, sizeof s.name) ||
        !readText("Email: ", s.email, sizeof s.email) ||
        !readText("Phone: ", s.phone, sizeof s.phone) ||
        !readText("Town: ", s.town, sizeof s.town))
        return;

    suppliers[supplierCount] = s;
    supplierCount++;

    printf("Supplier added successfully.\n");
}

void displaySuppliers(void)
{
    printf("\n--- SUPPLIER RECORDS ---\n");

    printf("%-6s %-39s %-39s %-14s %-19s\n",
           "ID", "Name", "Email", "Phone", "Town");

    for (int i = 0; i < supplierCount; i++) {
        printf("%-6d %-39s %-39s %-14s %-19s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }

    printf("Total suppliers: %d\n", supplierCount);
}

void addAsset(void)
{
    if (assetCount == MAX_RECORDS) {
        printf("Asset storage is full.\n");
        return;
    }

    Asset a;

    printf("\n--- ADD ASSET ---\n");

    if (!readInt("Asset ID: ", &a.id) ||
        !readText("Description: ", a.description,
                  sizeof a.description) ||
        !readDouble("Asset value: ", &a.value) ||
        !readDate("Date acquired:", &a.acquired))
        return;

    assets[assetCount] = a;
    assetCount++;

    printf("Asset added successfully.\n");
}

void displayAssets(void)
{
    printf("\n--- ASSET RECORDS ---\n");

    printf("%-6s %-39s %12s %-12s\n",
           "ID", "Description", "Value", "Acquired");

    for (int i = 0; i < assetCount; i++) {
        printf("%-6d %-39s %12.2f %02d/%02d/%04d\n",
               assets[i].id,
               assets[i].description,
               assets[i].value,
               assets[i].acquired.day,
               assets[i].acquired.month,
               assets[i].acquired.year);
    }

    printf("Total assets: %d\n", assetCount);
}

void addBudget(void)
{
    if (budgetCount == MAX_RECORDS) {
        printf("Budget storage is full.\n");
        return;
    }

    Budget b;

    printf("\n--- ADD DEPARTMENT BUDGET ---\n");

    if (!readText("Department: ", b.department,
                  sizeof b.department) ||
        !readDouble("Allocated amount: ", &b.allocated) ||
        !readDouble("Spent amount: ", &b.spent))
        return;

    budgets[budgetCount] = b;
    budgetCount++;

    printf("Budget added successfully.\n");
}

void displayBudgets(void)
{
    printf("\n--- DEPARTMENT BUDGET RECORDS ---\n");

    printf("%-19s %12s %12s %12s\n",
           "Department", "Allocated", "Spent", "Balance");

    for (int i = 0; i < budgetCount; i++) {
        printf("%-19s %12.2f %12.2f %12.2f\n",
               budgets[i].department,
               budgets[i].allocated,
               budgets[i].spent,
               budgets[i].allocated - budgets[i].spent);
    }

    printf("Total budgets: %d\n", budgetCount);
}

void addProject(void)
{
    if (projectCount == MAX_RECORDS) {
        printf("Project storage is full.\n");
        return;
    }

    Project p;

    printf("\n--- ADD PROJECT ---\n");

    if (!readInt("Project ID: ", &p.id) ||
        !readText("Project title: ", p.title,
                  sizeof p.title) ||
        !readDouble("Project budget: ", &p.budget) ||
        !readDate("Start date:", &p.startDate) ||
        !readDate("End date:", &p.endDate))
        return;

    projects[projectCount] = p;
    projectCount++;

    printf("Project added successfully.\n");
}

void displayProjects(void)
{
    printf("\n--- PROJECT RECORDS ---\n");

    printf("%-6s %-39s %12s %-12s %-12s\n",
           "ID", "Title", "Budget", "Start", "End");

    for (int i = 0; i < projectCount; i++) {
        printf(
            "%-6d %-39s %12.2f %02d/%02d/%04d   %02d/%02d/%04d\n",
            projects[i].id,
            projects[i].title,
            projects[i].budget,
            projects[i].startDate.day,
            projects[i].startDate.month,
            projects[i].startDate.year,
            projects[i].endDate.day,
            projects[i].endDate.month,
            projects[i].endDate.year
        );
    }

    printf("Total projects: %d\n", projectCount);
}
