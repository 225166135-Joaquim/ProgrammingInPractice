#include <stdio.h>
#include "utilities.h"

void displayMenu(void)
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    printf(" 1. Calculate Employee Salary\n");
    printf(" 2. Calculate VAT\n");
    printf(" 3. Calculate Budget Balance\n");
    printf(" 4. Search Stored Employee\n");
    printf(" 5. Add Employee\n");
    printf(" 6. Add Supplier\n");
    printf(" 7. Add Asset\n");
    printf(" 8. Add Department Budget\n");
    printf(" 9. Display All Records\n");
    printf("10. Save Data (text)\n");
    printf("11. Load Data (text)\n");
    printf("12. Save Employees (binary)\n");
    printf("13. Load Employees (binary)\n");
    printf("14. Backup Saved Data\n");
    printf("15. Exit\n");
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

