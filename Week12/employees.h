#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "records.h"

float calculateSalary(float basic, float housing, float transport);

int searchEmployee(int id, const int ids[], int size);

void swapSalaries(double *a, double *b);
void displaySalaries(const double salaries[], int n);
double findHighest(const double salaries[], int n);
double calculateAverage(const double salaries[], int n);
void giveRaise(double salaries[], int n, double percent);

void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id);

#endif