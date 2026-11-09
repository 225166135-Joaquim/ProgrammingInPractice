#include <stdio.h>
#include "utilities.h"

void displayMenu(void)
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    printf(" 1. Add Employee\n");
    printf(" 2. Display Employees\n");
    printf(" 3. Add Supplier\n");
    printf(" 4. Display Suppliers\n");
    printf(" 5. Add Asset\n");
    printf(" 6. Display Assets\n");
    printf(" 7. Add Budget\n");
    printf(" 8. Display Budgets\n");
    printf(" 9. Add Project\n");
    printf("10. Display Projects\n");

    printf("11. Save Text Data\n");
    printf("12. Load Text Data\n");
    printf("13. Save Employees (Binary)\n");
    printf("14. Load Employees (Binary)\n");

    printf("15. Calculate Salary\n");
    printf("16. Calculate VAT\n");
    printf("17. Calculate Budget\n");
    printf("18. Search Employee\n");
    printf("19. Update Employee Salary\n");
    printf("20. Exit\n");
}

int readFloat(const char prompt[], float *value)
{
    printf("%s", prompt);

    if (scanf("%f", value) != 1) {
        printf("Invalid number.\n");
        return 0;
    }

    return 1;
}

int readInt(const char prompt[], int *value)
{
    printf("%s", prompt);

    if (scanf("%d", value) != 1) {
        printf("Invalid number.\n");
        return 0;
    }

    return 1;
}