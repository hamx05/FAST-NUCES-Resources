#include <stdio.h>
#include <string.h>

struct Date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

struct Worker {
    int id;
    char first_name[20];
    char last_name[20];
    int salary;
    char department[20];
    struct Date joining_date;
};

struct Bonus {
    int worker_id;
    int amount;
    struct Date date;
};

struct Title {
    int worker_id;
    char worker_title[20];
    struct Date affected_from;
};

void printWorkerDetails(struct Worker *worker) {
    printf("\n%d\n", worker->id);
    puts(worker->first_name);
    puts(worker->last_name);
    printf("%d\n", worker->salary);
    printf("%d-%d-%d\n", worker->joining_date.year, worker->joining_date.month, worker->joining_date.day);
    puts(worker->department);
}

int main(void) {
    struct Worker workers[8];
    struct Bonus bonuses[5];
    struct Title titles[8];

    // Input data
    for (int i = 0; i < 5; i++) {
    	printf("Data for Worker %d\n", i+1);
        printf("Enter the worker id: ");
        scanf("%d", &workers[i].id);

        printf("\nEnter the first name: ");
        scanf("%s", &workers[i].first_name);

        printf("\nEnter the last name: ");
        scanf("%s", &workers[i].last_name);

        printf("\nEnter the salary: ");
        scanf("%d", &workers[i].salary);

        printf("\nEnter the year of joining: ");
        scanf("%d", &workers[i].joining_date.year);

        printf("\nEnter the month of joining: ");
        scanf("%d", &workers[i].joining_date.month);

        printf("\nEnter the date of joining: ");
        scanf("%d", &workers[i].joining_date.day);

        printf("\nEnter the department: ");
        scanf("%s", &workers[i].department);
        printf("\n");
    }

    // Calculate total salary and print details for each department
    int maxIndex=0, totalSalary = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(workers[i].department, "HR") == 0 || strcmp(workers[i].department, "Admin") == 0 ||
            strcmp(workers[i].department, "Account") == 0) {

            totalSalary += workers[i].salary;
            
            if (strcmp(workers[i].department, "HR") == 0 || strcmp(workers[i].department, "Admin") == 0 ||
                strcmp(workers[i].department, "Account") == 0) {
                
                if (workers[i].salary > workers[maxIndex].salary) {
                    maxIndex = i;
                }
            }
        }
    }

    // Print the worker with the highest salary in each department
    printf("Total salary in 'HR', 'Admin', and 'Account' departments is: %d\n", totalSalary);

    return 0;
}

