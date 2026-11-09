
#include <stdio.h>
#include <string.h>

int main(void)
{
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];

    char copiedName[100];
    char searchName[100];

    printf("====================================\n");
    printf("       SUPPLIER ASSESSMENT\n");
    printf("====================================\n");

    printf("Enter supplier name: ");
    scanf(" %99[^\n]", supplierName);

    printf("Enter email: ");
    scanf(" %99[^\n]", email);

    printf("Enter phone number: ");
    scanf(" %29[^\n]", phone);

    printf("Enter town: ");
    scanf(" %49[^\n]", town);

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Supplier Name: %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town: %s\n", town);

    printf("\n--- STRING LENGTH ---\n");
    printf("Supplier Name Length: %zu\n",
           strlen(supplierName));

    strcpy(copiedName, supplierName);

    printf("\n--- COPIED SUPPLIER NAME ---\n");
    printf("Original Name: %s\n", supplierName);
    printf("Copied Name: %s\n", copiedName);

    printf("\nEnter supplier name to search: ");
    scanf(" %99[^\n]", searchName);

    if (strcmp(supplierName, searchName) == 0) {
        printf("Supplier found.\n");
        printf("Supplier Name: %s\n", supplierName);
        printf("Email: %s\n", email);
        printf("Phone: %s\n", phone);
        printf("Town: %s\n", town);
    }
    else {
        printf("Supplier not found.\n");
    }

    return 0;
}
