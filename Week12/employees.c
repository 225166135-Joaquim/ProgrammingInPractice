#include <stdio.h>
#include <stddef.h>
#include "employees.h"

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

int searchEmployee(int id, const int ids[], int size)
{
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }

    return -1;
}

void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void displaySalaries(const double salaries[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n)
{
    if (n <= 0) {
        return 0.0;
    }

    double highest = salaries[0];

    for (int i = 1; i < n; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
    }

    return highest;
}

double calculateAverage(const double salaries[], int n)
{
    if (n <= 0) {
        return 0.0;
    }

    double total = 0.0;

    for (int i = 0; i < n; i++) {
        total += salaries[i];
    }

    return total / n;
}

void giveRaise(double salaries[], int n, double percent)
{
    for (int i = 0; i < n; i++) {
        salaries[i] += salaries[i] * percent / 100.0;
    }
}

void updateSalary(Employee *e, double newSalary)
{
    if (e != NULL) {
        e->salary = newSalary;
    }
}

Employee *findEmployee(Employee list[], int n, int id)
{
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i];
        }
    }

    return NULL;
}