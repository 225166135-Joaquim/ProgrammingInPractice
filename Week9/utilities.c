#include <stdio.h>
#include "utilities.h"

void displayMenu(void)
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
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
