#include <stdio.h>
#include <string.h>

struct joining_date {
    int year;
    int month;
    int date;
    int hour;
    int minute;
    int second;
} j_d;

struct worker {
    int worker_id;
    char first_name[20];
    char last_name[20];
    int salary;
    char department[20];
    struct joining_date j_d;
};

struct bonus_date {
    int year;
    int month;
    int date;
} b_d;

struct bonus {
    int worker_ref_id;
    int bonus_amount;
    struct bonus_date b_d;
};

struct affected_from {
    int year;
    int month;
    int date;
    int hour;
    int minute;
    int second;
} a_f;

struct title {
    int worker_ref_id;
    char worker_title[20];
    struct affected_from a_f;
};

int main() {
    struct worker worker[8];
    struct bonus bonus[5];
    struct title title[8];
    int i, n;

    printf("Enter the number of workers: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("\tData for Worker %d:\n", i + 1);
        printf("Enter the worker id: ");
        scanf("%d", &worker[i].worker_id);
        printf("Enter the first name: ");
        fgets(worker[i].first_name, sizeof(worker[i].first_name), stdin);
        printf("Enter the last name: ");
        fgets(worker[i].last_name, sizeof(worker[i].last_name), stdin);
        printf("Enter the salary: ");
        scanf("%d", &worker[i].salary);
        printf("Enter the year of joining: ");
        scanf("%d", &worker[i].j_d.year);
        printf("Enter the month of joining: ");
        scanf("%d", &worker[i].j_d.month);
        printf("Enter the date of joining: ");
        scanf("%d", &worker[i].j_d.date);
        printf("Enter the department: ");
        fgets(worker[i].department, sizeof(worker[i].department), stdin);
        printf("\n");
    }

    // Part A:
    printf("Workers having maximum salary from each department:\n");
    int max1 = 0, sum1 = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(worker[i].department, "HR") == 0) {
            sum1 = sum1 + worker[i].salary;
            if (max1 < worker[i].salary) {
                max1 = worker[i].salary;
                printf("\n%d\t", worker[i].worker_id);
                printf("%s\t", worker[i].first_name);
                printf("%s\t", worker[i].last_name);
                printf("%d\t", worker[i].salary);
                printf("%d-%d-%d\t", worker[i].j_d.year, worker[i].j_d.month, worker[i].j_d.date);
                printf("%s\t", worker[i].department);
            }
        }
    }

    int max2 = 0, sum2 = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(worker[i].department, "Admin") == 0) {
            sum2 = sum2 + worker[i].salary;
            if (max2 < worker[i].salary) {
                max2 = worker[i].salary;
                printf("\n%d\t", worker[i].worker_id);
                printf("%s\t", worker[i].first_name);
                printf("%s\t", worker[i].last_name);
                printf("%d\t", worker[i].salary);
                printf("%d-%d-%d\t", worker[i].j_d.year, worker[i].j_d.month, worker[i].j_d.date);
                printf("%s\t", worker[i].department);
            }
        }
    }

    int max3 = 0, sum3 = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(worker[i].department, "Account") == 0) {
            sum3 = sum3 + worker[i].salary;
            if (max3 < worker[i].salary) {
                max3 = worker[i].salary;
                printf("\n%d\t", worker[i].worker_id);
                printf("%s\t", worker[i].first_name);
                printf("%s\t", worker[i].last_name);
                printf("%d\t", worker[i].salary);
                printf("%d-%d-%d\t", worker[i].j_d.year, worker[i].j_d.month, worker[i].j_d.date);
                printf("%s\t", worker[i].department);
            }
        }
    }

    // Part B:
    printf("\n");
    printf("Total salary in 'HR' department is: %d\n", sum1);
    printf("Total salary in 'Admin' department is: %d\n", sum2);
    printf("Total salary in 'Account' department is: %d\n\n", sum3);

    return 0;
}

