#ifndef STORAGE_H
#define STORAGE_H

void addRecord(int type);
void displayRecords(void);
void searchStoredEmployee(int id);

void saveAllData(void);
void loadAllData(void);

void saveEmployeesBinary(void);
void loadEmployeesBinary(void);

void backupData(void);

#endif
