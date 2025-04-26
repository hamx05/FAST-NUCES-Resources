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
        "Abdul", "Bushra", "Chaudhry", "Danish", "Eman", "Faisal", "Gulzar", "Hina", "Irfan", "Javeria",
        "Khalid", "Laila", "Mansoor", "Naima", "Omar", "Parveen", "Qasim", "Rukhsar", "Saadia", "Tariq"
    };
    int numNames = sizeof(names) / sizeof(names[0]);
    int index = rand() % numNames;
    strncpy(name, names[index], sizeof(names[index]));
}

struct Employee initializeEmployee(const char *role) {
    struct Employee employee;
    generateRandomName(employee.name);
    strncpy(employee.role, role, sizeof(employee.role));
    employee.communication = rand() % 100 + 1;
    employee.teamwork = rand() % 100 + 1;
    employee.creativity = rand() % 100 + 1;
    return employee;
}

int main() {
    int i, j;
    const char *departments[] = {"HR", "Finance", "Marketing", "Logistics"};
    const char *roles[] = {"Director", "Manager", "Coordinator", "Team Member", "Trainee"};
    struct Employee employeesByDepartment[4][5];
	
	printf("Muhammad Hammad (23K-2005)\n\n");
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 5; ++j) {
            generateRandomName(employeesByDepartment[i][j].name);
            strncpy(employeesByDepartment[i][j].role, roles[j], sizeof(employeesByDepartment[i][j].role));
            employeesByDepartment[i][j].communication = rand() % 100 + 1;
            employeesByDepartment[i][j].teamwork = rand() % 100 + 1;
            employeesByDepartment[i][j].creativity = rand() % 100 + 1;
        }
    }

    // Printing the employee directory
    for (i = 0; i < 4; ++i) {
        printf("Department: %s\n", departments[i]);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Name\t\tRole\t\tCommunication\tTeamwork\tCreativity\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        for (j = 0; j < 5; ++j) {
            printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", employeesByDepartment[i][j].name,
                   employeesByDepartment[i][j].role, employeesByDepartment[i][j].communication,
                   employeesByDepartment[i][j].teamwork, employeesByDepartment[i][j].creativity);
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    }

   // Calculate the total scores for each department
int departmentSums[4] = {0};
for (i = 0; i < 4; ++i) {
    for (j = 0; j < 5; ++j) {
        departmentSums[i] += employeesByDepartment[i][j].communication +
                             employeesByDepartment[i][j].teamwork +
                             employeesByDepartment[i][j].creativity;
    }
}

// Find the best department
int bestDepartmentIndex = 0;
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
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("Name\t\tRole\t\tCommunication\tTeamwork\tCreativity\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

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

