#include<stdio.h>

#include<string.h>

struct worker {
    int worker_id;
    char first_name[20];
    char last_name[20];
    int salary;
    char department[20];
    struct joining_date {
        int year;
        int month;
        int date;
        int hour;
        int minute;
        int second;
    }
    j_d;
};
struct bonus {
    int worker_ref_id;
    int bonus_amount;
    struct bonus_date {
        int year;
        int month;
        int date;
        int hour;
        int minute;
        int second;
    }
    b_d;
};
struct title {
    int worker_ref_id;
    char worker_title[20];
    struct affected_from {
        int year;
        int month;
        int date;
        int hour;
        int minute;
        int second;
    }
    a_f;
};
void main(void) {
    struct worker w_var[8];
    struct bonus b_var[5];
    struct title t_var[8];
    int i;
    for (i = 0; i < 5; i++) {
        printf("Enter the worker id: ");
        scanf("%d", & w_var[i].worker_id);
        printf("\nEnter the first name: ");
        fflush(stdin);
        gets(w_var[i].first_name);
        printf("\nEnter the last name: ");
        fflush(stdin);
        gets(w_var[i].last_name);
        printf("\nEnter the salary: ");
        scanf("%d", & w_var[i].salary);
        printf("\nEnter the year of joining: ");
        scanf("%d", & w_var[i].j_d.year);
        printf("\nEnter the month of joining: ");
        scanf("%d", & w_var[i].j_d.month);
        printf("\nEnter the date of joining: ");
        scanf("%d", & w_var[i].j_d.date);
        printf("\nEnter the department: ");
        fflush(stdin);
        gets(w_var[i].department);
        printf("\n");
    }
    int max = 0, sum = 0;
    for (i = 0; i < 5; i++) {
        if (strcmp(w_var[i].department, "HR") == 0) {
            sum = sum + w_var[i].salary;
            if (max < w_var[i].salary) {
                max = w_var[i].salary;
                printf("\n%d\n", w_var[i].worker_id);
                puts(w_var[i].first_name);
                puts(w_var[i].last_name);
                printf("%d\n", w_var[i].salary);
                printf("%d-%d-%d\n", w_var[i].j_d.year, w_var[i].j_d.month, w_var[i].j_d.date);
                puts(w_var[i].department);
            }
        }
    }
    printf("Total salary in 'HR' department is: %d\n", sum);
    max = sum = 0;
    for (i = 0; i < 5; i++) {
        if (strcmp(w_var[i].department, "Admin") == 0) {
            sum = sum + w_var[i].salary;
            if (max < w_var[i].salary) {
                max = w_var[i].salary;
                printf("\n%d\n", w_var[i].worker_id);
                puts(w_var[i].first_name);
                puts(w_var[i].last_name);
                printf("%d\n", w_var[i].salary);
                printf("%d-%d-%d\n", w_var[i].j_d.year, w_var[i].j_d.month, w_var[i].j_d.date);
                puts(w_var[i].department);
            }
        }
    }
    printf("Total salary in 'Admin' department is: %d\n", sum);
    max = sum = 0;
    for (i = 0; i < 5; i++) {
        if (strcmp(w_var[i].department, "Account") == 0) {
            sum = sum + w_var[i].salary;
            if (max < w_var[i].salary) {
                max = w_var[i].salary;
                max = w_var[i].salary;
                printf("\n%d\n", w_var[i].worker_id);
                puts(w_var[i].first_name);
                puts(w_var[i].last_name);
                printf("%d\n", w_var[i].salary);
                printf("%d-%d-%d\n", w_var[i].j_d.year, w_var[i].j_d.month, w_var[i].j_d.date);
                puts(w_var[i].department);
            }
        }
    }
    printf("Total salary in 'Account' department is: %d\n", sum);
}
