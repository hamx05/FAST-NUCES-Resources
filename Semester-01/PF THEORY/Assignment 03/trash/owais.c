#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[20];
    char role[15];
    int communication;
    int teamwork;
    int creativity;
};

void generateRandomName(char *name) {
    static const char *names[] = {
        "Ayesha", "Bilal", "Farida", "Ghulam", "Hira", "Imran", "Javeria", "Kamran", "Lubna", "Munir",
	    "Nida", "Omar", "Parveen", "Qasim", "Rukhsar", "Saad", "Tahira", "Umar", "Vasia", "Yasir"
    };
    int numNames = sizeof(names) / sizeof(names[0]);
    static const char **usedNames = NULL;
    static int usedCount = 0;
    if (usedCount == numNames) {
        usedCount = 0;
        free(usedNames);
        usedNames = NULL;
    }
    if (usedNames == NULL) {
        usedNames = malloc(numNames * sizeof(const char *));
        if (usedNames == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < numNames; ++i) {
            usedNames[i] = NULL;
        }
    }
    int index;
    do {
        index = rand() % numNames;
    } while (usedNames[index] != NULL);
    strcpy(name, names[index]);
    usedNames[index] = names[index];
    usedCount++;
}

struct Employee initializeEmployee(const char *role) {
    struct Employee employee;
    generateRandomName(employee.name);
    strcpy(employee.role, role);
    employee.communication = rand() % 100 + 1;
    employee.teamwork = rand() % 100 + 1;
    employee.creativity = rand() % 100 + 1;
    return employee;
}

int main() {
	int i=0,j=0;
	printf("\t\t\t\tNAME: MUHAMMAD OWAIS MUHAMMAD RAFIQ\n");
	printf("\t\t\t\tROLL NO: 23K-2042\n\n");
    const char *departments[] = {"HR", "Finance", "Marketing", "Logistics"};
    const char *roles[] = {"Director", "Executive", "Manager", "Employee", "Trainee"};
    struct Employee employeesByDepartment[4][5];
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 5; ++j) {
            strcpy(employeesByDepartment[i][j].role, roles[j]);
        }
        for (j = 0; j < 5; ++j) {
            generateRandomName(employeesByDepartment[i][j].name);
            employeesByDepartment[i][j].communication = rand() % 100 + 1;
            employeesByDepartment[i][j].teamwork = rand() % 100 + 1;
            employeesByDepartment[i][j].creativity = rand() % 100 + 1;
        }
    }
    for (i = 0; i < 4; ++i) {
        printf("Department: %s\n", departments[i]);
        printf("----------------------------------------\n");
        printf("Name\t\tRole\t\tCommunication\tTeamwork\tCreativity\n");
        printf("----------------------------------------\n");
        for (j = 0; j < 5; ++j) {
            printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", employeesByDepartment[i][j].name,
                   employeesByDepartment[i][j].role, employeesByDepartment[i][j].communication,
                   employeesByDepartment[i][j].teamwork, employeesByDepartment[i][j].creativity);
        }

        printf("----------------------------------------\n\n");
    }
    int departmentSums[4] = {0};
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 5; ++j) {
            departmentSums[i] += employeesByDepartment[i][j].communication +
                                 employeesByDepartment[i][j].teamwork +
                                 employeesByDepartment[i][j].creativity;
        }
    }
    int bestDepartmentIndex = 0;
    for (i = 1; i < 4; ++i) {
        if (departmentSums[i] > departmentSums[bestDepartmentIndex]) {
            bestDepartmentIndex = i;
        }
    }
    printf("Department Sums:\n");
    for (i = 0; i < 4; ++i) {
        printf("%s: %d\n", departments[i], departmentSums[i]);
    }
    printf("\nBest Department: %s\n", departments[bestDepartmentIndex]);
    if(departments[bestDepartmentIndex] == "HR")
    	i=0;
    if(departments[bestDepartmentIndex] == "Finance")
    	i=1;
	if(departments[bestDepartmentIndex] == "Marketing")
    	i=2;
	if(departments[bestDepartmentIndex] == "Logistics")
    	i=3;			
        printf("----------------------------------------\n");
        printf("Name\t\tRole\t\tCommunication\tTeamwork\tCreativity\n");
        printf("----------------------------------------\n");

        for (j = 0; j < 5; ++j) {
            printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", employeesByDepartment[i][j].name,
                   employeesByDepartment[i][j].role, employeesByDepartment[i][j].communication,
                   employeesByDepartment[i][j].teamwork, employeesByDepartment[i][j].creativity);
        }
// Calculate the total scores for each department
for (i = 0; i < 4; ++i) {
    for (j = 0; j < 5; ++j) {
        departmentSums[i] += employeesByDepartment[i][j].communication +
                             employeesByDepartment[i][j].teamwork +
                             employeesByDepartment[i][j].creativity;
    }
}

// Find the best department
for (i = 1; i < 4; ++i) {
    if (departmentSums[i] > departmentSums[bestDepartmentIndex]) {
        bestDepartmentIndex = i;
    }
}

// Print department sums
printf("Department Sums:\n");
for (i = 0; i < 4; ++i) {
    printf("%s: %d\n", departments[i], departmentSums[i]);
}
printf("\nBest Department: %s\n", departments[bestDepartmentIndex]);

// Print details for the best department
printf("----------------------------------------\n");
printf("Name\t\tRole\t\tCommunication\tTeamwork\tCreativity\n");
printf("----------------------------------------\n");

// Use the bestDepartmentIndex to print details for the best department
for (j = 0; j < 5; ++j) {
    printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", employeesByDepartment[bestDepartmentIndex][j].name,
           employeesByDepartment[bestDepartmentIndex][j].role,
           employeesByDepartment[bestDepartmentIndex][j].communication,
           employeesByDepartment[bestDepartmentIndex][j].teamwork,
           employeesByDepartment[bestDepartmentIndex][j].creativity);
}

return 0;
}
