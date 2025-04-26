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
    strcpy(name, names[index]);
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
    int i = 0, j = 0;
    printf("\tMuhammad Hammad (23K-2005)\n\n");
    const char *departments[] = {"HR", "Finance", "Marketing", "Logistics"};
    const char *roles[] = {"Director", "Manager", "Coordinator", "Team Member", "Trainee"};
    struct Employee employeesByDepartment[4][5];

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 5; ++j) {
            strcpy(employeesByDepartment[i][j].role, roles[j]);
            generateRandomName(employeesByDepartment[i][j].name);
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
    strcpy(name, names[index]);
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
    int i = 0, j = 0;
    const char *departments[] = {"HR", "Finance", "Marketing", "Logistics"};
    const char *roles[] = {"Director", "Manager", "Coordinator", "Team Member", "Trainee"};
    struct Employee employeesByDepartment[4][5];

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 5; ++j) {
            strcpy(employeesByDepartment[i][j].role, roles[j]);
            generateRandomName(employeesByDepartment[i][j].name);
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

    return 0;
}}

