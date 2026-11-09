
#include <stdio.h>

int main(void)
{
    char supplierName[50];
    float price;
    float budget;
    int registered;
    int documentsComplete;

    printf("====================================\n");
    printf("       TENDER EVALUATION SYSTEM\n");
    printf("====================================\n");

    printf("Enter supplier name: ");
    scanf("%49s", supplierName);

    printf("Enter tender price: ");
    scanf("%f", &price);

    printf("Enter available budget: ");
    scanf("%f", &budget);

    printf("Is supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered);

    printf("Are all documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documentsComplete);

    printf("\n--- TENDER EVALUATION RESULT ---\n");
    printf("Supplier: %s\n", supplierName);

    if (registered == 0 || documentsComplete == 0) {
        printf("Status: Disqualified\n");
    }
    else if (price > budget) {
        printf("Status: Disqualified\n");
    }
    else {
        printf("Status: Qualified\n");
    }

    return 0;
}
