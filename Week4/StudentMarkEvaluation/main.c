
#include <stdio.h>

int main(void)
{
    char studentName[50];
    float test1;
    float test2;
    float assignment;
    float total;

    printf("====================================\n");
    printf("      STUDENT MARK CALCULATOR\n");
    printf("====================================\n");

    printf("Enter student name: ");
    scanf(" %49[^\n]", studentName);

    printf("Enter Test 1 mark: ");
    scanf("%f", &test1);

    printf("Enter Test 2 mark: ");
    scanf("%f", &test2);

    printf("Enter Assignment mark: ");
    scanf("%f", &assignment);

    total = test1 + test2 + assignment;

    printf("\n--- STUDENT RESULTS ---\n");
    printf("Student Name: %s\n", studentName);
    printf("Total Mark: %.2f\n", total);

    if (total >= 75 && total <= 100) {
        printf("Result: Distinction\n");
    }
    else if (total >= 60 && total < 75) {
        printf("Result: Credit\n");
    }
    else if (total >= 50 && total < 60) {
        printf("Result: Pass\n");
    }
    else if (total >= 0 && total < 50) {
        printf("Result: Fail\n");
    }
    else {
        printf("Result: Invalid total mark\n");
    }

    return 0;
}
