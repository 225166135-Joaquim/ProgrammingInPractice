
# Municipal Financial Management System - Week 9

## Project Description

This project modularises the Municipal Financial Management System (MFMS) developed during Weeks 1-8.

The program demonstrates multi-file programming, function declarations, function definitions, header files, separate compilation and linking in C.

## Project Files

- main.c: Controls the main menu and program execution.
- employees.c: Calculates employee salaries and searches employee IDs.
- employees.h: Employee function declarations.
- budget.c: Calculates VAT and budget balances.
- budget.h: Budget function declarations.
- utilities.c: Displays the menu and handles numerical input.
- utilities.h: Utility function declarations.
- reports.c: Displays salary, VAT and budget reports.
- reports.h: Report function declarations.

## Compilation

Compile each source file separately:

gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c

Link the object files:

gcc main.o employees.o budget.o utilities.o reports.o -o mfms

Run:

./mfms

## Testing

Test 1: Employee salary calculation.
Test 2: VAT calculation.
Test 3: Budget calculation.
Test 4: Employee ID search.

## Week 9 Concepts

- Modular programming
- Header files and include guards
- Function prototypes
- Separate compilation
- Linking object files
- Reusable functions
