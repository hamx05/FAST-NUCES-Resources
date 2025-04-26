#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct EmployeePersonal {
    int id;
    char name[40];
} EmployeePersonal;

typedef struct EmployeeDepartment {
    int id;
    int salary;
} EmployeeDepartment;

void combineEmployees(int n);

int main(void) {
    printf("Muhammad Hammad (23K-2005)\n\n");
    int i=0, n=0;
    
    printf("Please enter the number of employees: ");
    scanf("%d", &n);

    EmployeePersonal personalInfo[n];
    for (i = 0; i < n; i++) {
        printf("Enter the id of employee %d: ", i+1);
        scanf("%d", &personalInfo[i].id);
        fflush(stdin);
        printf("Enter the name of employee %d: ", i+1);
        fflush(stdin);
        gets(personalInfo[i].name);
    }

    FILE *personalFile = fopen("Personal.txt", "w");
    if (personalFile == NULL) {
        printf("Error opening the file\n");
        exit(0);
    }
    for (i=0; i<n; i++) {
        fprintf(personalFile, "%d %s\n", personalInfo[i].id, personalInfo[i].name);
    }
    fclose(personalFile);

    EmployeeDepartment departmentInfo[n];
    for (i=0; i<n; i++) {
        printf("Enter id of employee %d: ", i + 1);
        scanf("%d", &departmentInfo[i].id);
        printf("Enter salary of employee %d: ", i + 1);
        scanf("%d", &departmentInfo[i].salary);
    }

    FILE *departmentFile = fopen("Department.txt", "w");
    if (departmentFile == NULL) {
        printf("Error opening the file\n"); // agar file na bani tou, jo sir ne bataya tha
        exit(0);
    }
    for (i=0; i<n; i++) {
        fprintf(departmentFile, "%d %d\n", departmentInfo[i].id, departmentInfo[i].salary);
    }
    fclose(departmentFile);

    combineEmployees(n);

    return 0;
}

void combineEmployees(int n) {
    int i, j;
    EmployeePersonal personalData[n];
    EmployeeDepartment departmentData[n];

    FILE *personalFile = fopen("Personal.txt", "r");
    if (personalFile == NULL) {
        printf("Error opening the file\n"); // agar file na bani tou, jo sir ne bataya tha
        exit(0);
    }
    for (i=0; i<n; i++) {
        fscanf(personalFile, "%d %s\n", &personalData[i].id, &personalData[i].name);
    }
    fclose(personalFile);

    FILE *departmentFile = fopen("Department.txt", "r");
    if (departmentFile == NULL) {
        printf("Error opening the file\n"); // agar file na bani tou, jo sir ne bataya tha
        exit(0);
    }
    for (i=0; i<n; i++) {
        fscanf(departmentFile, "%d %d\n", &departmentData[i].id, &departmentData[i].salary);
    }
    fclose(departmentFile);

    FILE *mergedFile = fopen("Combine.txt", "w");
    if (mergedFile == NULL) {
        printf("Error opening the file\n");
        exit(0);
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (personalData[i].id == departmentData[j].id) {
                fprintf(mergedFile, "%d %s %d\n", personalData[i].id, personalData[i].name, departmentData[j].salary);
            }
        }
    }

    fclose(mergedFile);
}

