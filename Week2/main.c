#include <stdio.h>

int main(){
    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("MUNICIPAL FINANCIAL SUMMARY\n\n");

    printf("Enter number of departments: ");
    scanf("%d", &departments);

    printf("Enter total payroll: ");
    scanf("%lf", &payroll);

    printf("Enter total procurement: ");
    scanf("%lf", &procurement);

    printf("Enter total assets: ");
    scanf("%lf", &assets);

    printf("\n-----------------------------\n");
    printf("Municipal Financial Summary\n");
    printf("-----------------------------\n");

    printf("Departments : %d\n", departments);
    printf("Payroll     : %.2f\n", payroll);
    printf("Procurement : %.2f\n", procurement);
    printf("Assets      : %.2f\n", assets);

    return 0;
}