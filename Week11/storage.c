#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "storage.h"
#include "records.h"

static const char *paths[5] = {
    "data/employees.txt",
    "data/suppliers.txt",
    "data/assets.txt",
    "data/budgets.txt",
    "data/projects.txt"
};

static const char *names[5] = {
    "employees",
    "suppliers",
    "assets",
    "budgets",
    "projects"
};

void saveTextData(void)
{
    for (int type = 0; type < 5; type++) {
        FILE *fp = fopen(paths[type], "w");

        if (fp == NULL) {
            perror(paths[type]);
            continue;
        }

        int count = 0;
        int ok = 1;

        switch (type) {
            case 0:
                count = employeeCount;

                for (int i = 0; i < count; i++) {
                    if (fprintf(fp, "%d|%s|%s|%.2f\n",
                                employees[i].id,
                                employees[i].name,
                                employees[i].department,
                                employees[i].salary) < 0)
                        ok = 0;
                }
                break;

            case 1:
                count = supplierCount;

                for (int i = 0; i < count; i++) {
                    if (fprintf(fp, "%d|%s|%s|%s|%s\n",
                                suppliers[i].id,
                                suppliers[i].name,
                                suppliers[i].email,
                                suppliers[i].phone,
                                suppliers[i].town) < 0)
                        ok = 0;
                }
                break;

            case 2:
                count = assetCount;

                for (int i = 0; i < count; i++) {
                    if (fprintf(fp, "%d|%s|%.2f|%d|%d|%d\n",
                                assets[i].id,
                                assets[i].description,
                                assets[i].value,
                                assets[i].acquired.day,
                                assets[i].acquired.month,
                                assets[i].acquired.year) < 0)
                        ok = 0;
                }
                break;

            case 3:
                count = budgetCount;

                for (int i = 0; i < count; i++) {
                    if (fprintf(fp, "%s|%.2f|%.2f\n",
                                budgets[i].department,
                                budgets[i].allocated,
                                budgets[i].spent) < 0)
                        ok = 0;
                }
                break;

            case 4:
                count = projectCount;

                for (int i = 0; i < count; i++) {
                    if (fprintf(
                            fp,
                            "%d|%s|%.2f|%d|%d|%d|%d|%d|%d\n",
                            projects[i].id,
                            projects[i].title,
                            projects[i].budget,
                            projects[i].startDate.day,
                            projects[i].startDate.month,
                            projects[i].startDate.year,
                            projects[i].endDate.day,
                            projects[i].endDate.month,
                            projects[i].endDate.year) < 0)
                        ok = 0;
                }
                break;
        }

        if (fclose(fp) != 0)
            ok = 0;

        if (ok) {
            printf("Saved %d %s.\n", count, names[type]);
        }
        else {
            perror(paths[type]);
        }
    }
}

static int parseRecord(int type, char *line)
{
    int end = -1;
    int assigned = 0;

    line[strcspn(line, "\r\n")] = '\0';
    int length = (int)strlen(line);

    if (type == 0 && employeeCount < MAX_RECORDS) {
        Employee e;

        assigned = sscanf(
            line,
            "%d|%29[^|]|%19[^|]|%lf%n",
            &e.id, e.name, e.department, &e.salary, &end
        );

        if (assigned == 4 && end == length) {
            employees[employeeCount++] = e;
            return 1;
        }
    }
    else if (type == 1 && supplierCount < MAX_RECORDS) {
        Supplier s;

        assigned = sscanf(
            line,
            "%d|%39[^|]|%39[^|]|%14[^|]|%19[^|]%n",
            &s.id, s.name, s.email, s.phone, s.town, &end
        );

        if (assigned == 5 && end == length) {
            suppliers[supplierCount++] = s;
            return 1;
        }
    }
    else if (type == 2 && assetCount < MAX_RECORDS) {
        Asset a;

        assigned = sscanf(
            line,
            "%d|%39[^|]|%lf|%d|%d|%d%n",
            &a.id, a.description, &a.value,
            &a.acquired.day,
            &a.acquired.month,
            &a.acquired.year,
            &end
        );

        if (assigned == 6 && end == length) {
            assets[assetCount++] = a;
            return 1;
        }
    }
    else if (type == 3 && budgetCount < MAX_RECORDS) {
        Budget b;

        assigned = sscanf(
            line,
            "%19[^|]|%lf|%lf%n",
            b.department, &b.allocated, &b.spent, &end
        );

        if (assigned == 3 && end == length) {
            budgets[budgetCount++] = b;
            return 1;
        }
    }
    else if (type == 4 && projectCount < MAX_RECORDS) {
        Project p;

        assigned = sscanf(
            line,
            "%d|%39[^|]|%lf|%d|%d|%d|%d|%d|%d%n",
            &p.id,
            p.title,
            &p.budget,
            &p.startDate.day,
            &p.startDate.month,
            &p.startDate.year,
            &p.endDate.day,
            &p.endDate.month,
            &p.endDate.year,
            &end
        );

        if (assigned == 9 && end == length) {
            projects[projectCount++] = p;
            return 1;
        }
    }

    return 0;
}

void loadTextData(void)
{
    for (int type = 0; type < 5; type++) {
        FILE *fp = fopen(paths[type], "r");

        if (fp == NULL) {
            if (errno == ENOENT)
                printf("File not found: %s\n", paths[type]);
            else
                perror(paths[type]);

            continue;
        }

        if (type == 0) employeeCount = 0;
        if (type == 1) supplierCount = 0;
        if (type == 2) assetCount = 0;
        if (type == 3) budgetCount = 0;
        if (type == 4) projectCount = 0;

        char line[512];
        int loaded = 0;
        int skipped = 0;

        while (fgets(line, sizeof line, fp) != NULL) {
            if (strchr(line, '\n') == NULL && !feof(fp)) {
                int c;

                while ((c = fgetc(fp)) != '\n' && c != EOF) {
                }

                skipped++;
                continue;
            }

            if (parseRecord(type, line))
                loaded++;
            else
                skipped++;
        }

        if (ferror(fp))
            perror(paths[type]);

        if (fclose(fp) != 0)
            perror(paths[type]);

        printf(
            "Loaded %d %s (skipped %d invalid).\n",
            loaded, names[type], skipped
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

    int ok = fwrite(
        &employeeCount,
        sizeof employeeCount,
        1,
        fp
    ) == 1;

    if (ok && employeeCount > 0) {
        ok = fwrite(
            employees,
            sizeof employees[0],
            employeeCount,
            fp
        ) == (size_t)employeeCount;
    }

    if (fclose(fp) != 0)
        ok = 0;

    if (ok)
        printf("Saved %d employees in binary format.\n",
               employeeCount);
    else
        printf("Could not save all employee records.\n");
}

void loadEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "rb");

    if (fp == NULL) {
        perror("data/employees.dat");
        return;
    }

    int count;
    Employee temp[MAX_RECORDS];

    int ok = fread(
        &count,
        sizeof count,
        1,
        fp
    ) == 1;

    if (ok && (count < 0 || count > MAX_RECORDS))
        ok = 0;

    if (ok && count > 0) {
        ok = fread(
            temp,
            sizeof temp[0],
            count,
            fp
        ) == (size_t)count;
    }

    if (fclose(fp) != 0)
        ok = 0;

    if (ok) {
        memcpy(
            employees,
            temp,
            (size_t)count * sizeof employees[0]
        );

        employeeCount = count;

        printf(
            "Loaded %d employees from binary file.\n",
            employeeCount
        );
    }
    else {
        printf("Binary employee file is invalid or incomplete.\n");
    }
}
