#ifndef RECORDS_H
#define RECORDS_H

#define MAX_RECORDS 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

typedef struct {
    int id;
    char name[40];
    char email[40];
    char phone[15];
    char town[20];
} Supplier;

typedef struct {
    int id;
    char description[40];
    double value;
    Date acquired;
} Asset;

typedef struct {
    char department[20];
    double allocated;
    double spent;
} Budget;

typedef struct {
    int id;
    char title[40];
    double budget;
    Date startDate;
    Date endDate;
} Project;

extern Employee employees[MAX_RECORDS];
extern Supplier suppliers[MAX_RECORDS];
extern Asset assets[MAX_RECORDS];
extern Budget budgets[MAX_RECORDS];
extern Project projects[MAX_RECORDS];

extern int employeeCount;
extern int supplierCount;
extern int assetCount;
extern int budgetCount;
extern int projectCount;

void addEmployee(void);
void displayEmployees(void);

void addSupplier(void);
void displaySuppliers(void);

void addAsset(void);
void displayAssets(void);

void addBudget(void);
void displayBudgets(void);

void addProject(void);
void displayProjects(void);

#endif
