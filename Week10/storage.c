#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "storage.h"
#include "utilities.h"

enum {
    EMPLOYEES,
    SUPPLIERS,
    ASSETS,
    BUDGETS,
    CATEGORIES = 4,
    LIMIT = 100,
    WIDTH = 256
};

static char records[CATEGORIES][LIMIT][WIDTH];
static int counts[CATEGORIES] = {0};

static const char *labels[CATEGORIES] = {
    "Employees", "Suppliers", "Assets", "Budgets"
};

static const char *paths[CATEGORIES] = {
    "data/employees.txt",
    "data/suppliers.txt",
    "data/assets.txt",
    "data/budgets.txt"
};

static const char *backupPaths[CATEGORIES] = {
    "data/employees_backup.txt",
    "data/suppliers_backup.txt",
    "data/assets_backup.txt",
    "data/budgets_backup.txt"
};

static int readName(const char *prompt, char *value, size_t size)
{
    int c;

    printf("%s", prompt);

    do {
        c = getchar();
    } while (c == '\n' || c == '\r');

    if (c == EOF)
        return 0;

    ungetc(c, stdin);

    if (fgets(value, (int)size, stdin) == NULL)
        return 0;

    size_t length = strcspn(value, "\r\n");

    if (value[length] == '\0' && length == size - 1) {
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        printf("Input is too long.\n");
        return 0;
    }

    value[length] = '\0';

    if (value[0] == '\0' || strchr(value, '|') != NULL) {
        printf("Text cannot be empty or contain '|'.\n");
        return 0;
    }

    return 1;
}

static int recordId(const char *line)
{
    int id;

    if (sscanf(line, "%d|", &id) != 1 || id <= 0)
        return -1;

    return id;
}

static int hasId(int type, int id)
{
    for (int i = 0; i < counts[type]; i++) {
        if (recordId(records[type][i]) == id)
            return 1;
    }

    return 0;
}

static int validRecord(int type, const char *line)
{
    int id;
    int end = 0;
    int parsed = 0;

    char a[60], b[60], c[60], d[60];
    double x, y;

    if (type == EMPLOYEES) {
        parsed = sscanf(
            line, "%d|%49[^|]|%lf%n",
            &id, a, &x, &end
        ) == 3;
    }
    else if (type == SUPPLIERS) {
        parsed = sscanf(
            line, "%d|%49[^|]|%59[^|]|%29[^|]|%49[^|]%n",
            &id, a, b, c, d, &end
        ) == 5;
    }
    else if (type == ASSETS) {
        parsed = sscanf(
            line, "%d|%59[^|]|%lf%n",
            &id, a, &x, &end
        ) == 3;
    }
    else if (type == BUDGETS) {
        parsed = sscanf(
            line, "%d|%49[^|]|%lf|%lf%n",
            &id, a, &x, &y, &end
        ) == 4;
    }

    return parsed && id > 0 &&
           end > 0 && line[end] == '\0';
}

void addRecord(int type)
{
    int id;
    float first = 0.0f;
    float second = 0.0f;

    char a[60], b[60], c[60], d[60];
    char line[WIDTH];

    if (type < 0 || type >= CATEGORIES)
        return;

    if (counts[type] == LIMIT) {
        printf("%s storage is full.\n", labels[type]);
        return;
    }

    printf("\n--- Add %s ---\n", labels[type]);

    if (!readInt("ID: ", &id))
        return;

    if (id <= 0 || hasId(type, id)) {
        printf("ID must be positive and unique.\n");
        return;
    }

    if (type == EMPLOYEES) {
        if (!readName("Employee name: ", a, 50) ||
            !readFloat("Salary: ", &first))
            return;

        snprintf(
            line, sizeof line,
            "%d|%s|%.2f", id, a, first
        );
    }
    else if (type == SUPPLIERS) {
        if (!readName("Supplier name: ", a, 50) ||
            !readName("Email: ", b, 60) ||
            !readName("Phone: ", c, 30) ||
            !readName("Town: ", d, 50))
            return;

        snprintf(
            line, sizeof line,
            "%d|%s|%s|%s|%s",
            id, a, b, c, d
        );
    }
    else if (type == ASSETS) {
        if (!readName("Asset description: ", a, 60) ||
            !readFloat("Asset value: ", &first))
            return;

        snprintf(
            line, sizeof line,
            "%d|%s|%.2f", id, a, first
        );
    }
    else {
        if (!readName("Department: ", a, 50) ||
            !readFloat("Allocated budget: ", &first) ||
            !readFloat("Amount spent: ", &second))
            return;

        snprintf(
            line, sizeof line,
            "%d|%s|%.2f|%.2f",
            id, a, first, second
        );
    }

    strcpy(records[type][counts[type]], line);
    counts[type]++;

    printf("Record added.\n");
}

void displayRecords(void)
{
    for (int type = 0; type < CATEGORIES; type++) {
        printf(
            "\n--- %s (%d) ---\n",
            labels[type], counts[type]
        );

        for (int i = 0; i < counts[type]; i++) {
            printf("%s\n", records[type][i]);
        }
    }

    printf("Record fields are separated by |.\n");
}

void searchStoredEmployee(int id)
{
    for (int i = 0; i < counts[EMPLOYEES]; i++) {
        if (recordId(records[EMPLOYEES][i]) == id) {
            printf(
                "Employee found: %s\n",
                records[EMPLOYEES][i]
            );
            return;
        }
    }

    printf("Employee not found.\n");
}

void saveAllData(void)
{
    for (int type = 0; type < CATEGORIES; type++) {
        FILE *fp = fopen(paths[type], "w");

        if (fp == NULL) {
            perror(paths[type]);
            continue;
        }

        int success = 1;

        for (int i = 0; i < counts[type]; i++) {
            if (fprintf(fp, "%s\n", records[type][i]) < 0) {
                success = 0;
                perror(paths[type]);
                break;
            }
        }

        if (fclose(fp) != 0) {
            success = 0;
            perror(paths[type]);
        }

        if (success) {
            printf(
                "Saved %d %s records.\n",
                counts[type], labels[type]
            );
        }
    }
}

void loadAllData(void)
{
    char line[512];

    for (int type = 0; type < CATEGORIES; type++) {
        FILE *fp = fopen(paths[type], "r");

        if (fp == NULL) {
            if (errno == ENOENT) {
                printf(
                    "Missing file: %s\n",
                    paths[type]
                );
            }
            else {
                perror(paths[type]);
            }

            continue;
        }

        counts[type] = 0;
        int invalid = 0;

        while (fgets(line, sizeof line, fp) != NULL) {
            size_t size = strlen(line);

            if (size &&
                line[size - 1] != '\n' &&
                !feof(fp)) {

                int c;

                while ((c = fgetc(fp)) != '\n' &&
                       c != EOF) {
                }

                invalid++;
                continue;
            }

            line[strcspn(line, "\r\n")] = '\0';

            if (!validRecord(type, line)) {
                invalid++;
                continue;
            }

            int id = recordId(line);

            if (hasId(type, id) ||
                counts[type] >= LIMIT) {
                invalid++;
                continue;
            }

            strcpy(
                records[type][counts[type]],
                line
            );

            counts[type]++;
        }

        if (ferror(fp))
            perror(paths[type]);

        fclose(fp);

        printf(
            "Loaded %d %s records; skipped %d invalid records.\n",
            counts[type], labels[type], invalid
        );
    }
}

void saveEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "wb");

    if (fp == NULL) {
        perror("data/employees.dat");
        return;
    }

    int written = 0;

    for (int i = 0; i < counts[EMPLOYEES]; i++) {
        if (fwrite(
                records[EMPLOYEES][i],
                WIDTH, 1, fp
            ) != 1) {
            perror("Binary employee write");
            break;
        }

        written++;
    }

    if (fclose(fp) != 0)
        perror("Closing employee binary file");

    printf(
        "Saved %d employees in binary format.\n",
        written
    );
}

void loadEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "rb");

    if (fp == NULL) {
        perror("data/employees.dat");
        return;
    }

    counts[EMPLOYEES] = 0;

    char line[WIDTH];
    int invalid = 0;

    while (fread(line, WIDTH, 1, fp) == 1) {
        if (memchr(line, '\0', WIDTH) == NULL ||
            !validRecord(EMPLOYEES, line) ||
            hasId(EMPLOYEES, recordId(line)) ||
            counts[EMPLOYEES] == LIMIT) {

            invalid++;
            continue;
        }

        memcpy(
            records[EMPLOYEES][counts[EMPLOYEES]],
            line, WIDTH
        );

        counts[EMPLOYEES]++;
    }

    if (ferror(fp))
        perror("Binary employee read");

    fclose(fp);

    printf(
        "Loaded %d employees from binary; skipped %d invalid records.\n",
        counts[EMPLOYEES], invalid
    );
}

void backupData(void)
{
    unsigned char buffer[1024];

    for (int type = 0; type < CATEGORIES; type++) {
        FILE *src = fopen(paths[type], "rb");

        if (src == NULL) {
            if (errno == ENOENT)
                printf("No file to back up: %s\n", paths[type]);
            else
                perror(paths[type]);

            continue;
        }

        FILE *dst = fopen(backupPaths[type], "wb");

        if (dst == NULL) {
            perror(backupPaths[type]);
            fclose(src);
            continue;
        }

        size_t n;
        int success = 1;

        while ((n = fread(
                buffer, 1, sizeof buffer, src
            )) > 0) {

            if (fwrite(buffer, 1, n, dst) != n) {
                perror(backupPaths[type]);
                success = 0;
                break;
            }
        }

        if (ferror(src)) {
            perror(paths[type]);
            success = 0;
        }

        fclose(src);

        if (fclose(dst) != 0) {
            perror(backupPaths[type]);
            success = 0;
        }

        if (success)
            printf("Backed up %s.\n", labels[type]);
    }
}
