#include<stdio.h>
#include<string.h>

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

int main(void) {
    struct worker wk[8];
    struct bonus bonus[5];
    struct title title[8];
    int i, j, n;

    printf("Enter the number of workers: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("\tData for Worker %d:\n", i + 1);
        printf("Enter the worker id: ");
        scanf("%d", &wk[i].worker_id);
        printf("Enter the first name: ");
        fflush(stdin);
        gets(wk[i].first_name);
        printf("Enter the last name: ");
        fflush(stdin);
        gets(wk[i].last_name);
        printf("Enter the salary: ");
        scanf("%d", &wk[i].salary);
        printf("Enter the year of joining: ");
        scanf("%d", &wk[i].j_d.year);
        printf("Enter the month of joining: ");
        scanf("%d", &wk[i].j_d.month);
        printf("Enter the date of joining: ");
        scanf("%d", &wk[i].j_d.date);
        printf("Enter the department: ");
        fflush(stdin);
        gets(wk[i].department);
        printf("\n");
    }

    


// Part A:
    printf("Workers having the maximum salary from each department:\n");

    int max1 = 0, sum1 = 0, index1 = -1;
    for (i = 0; i < n; i++) {
        if (strcmp(wk[i].department, "HR") == 0) {
            sum1 = sum1 + wk[i].salary;
            if (max1 < wk[i].salary) {
                max1 = wk[i].salary;
                index1 = i;  // Update the index when a higher salary is found
            }
        }
    }

    if (index1 != -1) {
        printf("%d\t", wk[index1].worker_id);
        printf("%s\t", wk[index1].first_name);
        printf("%s\t", wk[index1].last_name);
        printf("%d\t", wk[index1].salary);
        printf("%d-%d-%d\t", wk[index1].j_d.year, wk[index1].j_d.month, wk[index1].j_d.date);
        printf("%s\t", wk[index1].department);
    }

    // Similar logic for the Admin department
    int max2 = 0, sum2 = 0, index2 = -1;
    for (i = 0; i < n; i++) {
        if (strcmp(wk[i].department, "Admin") == 0) {
            sum2 = sum2 + wk[i].salary;
            if (max2 < wk[i].salary) {
                max2 = wk[i].salary;
                index2 = i;  // Update the index when a higher salary is found
            }
        }
    }

    if (index2 != -1) {
        printf("\n%d\t", wk[index2].worker_id);
        printf("%s\t", wk[index2].first_name);
        printf("%s\t", wk[index2].last_name);
        printf("%d\t", wk[index2].salary);
        printf("%d-%d-%d\t", wk[index2].j_d.year, wk[index2].j_d.month, wk[index2].j_d.date);
        printf("%s\t", wk[index2].department);
    }

    // Similar logic for the Account department
    int max3 = 0, sum3 = 0, index3 = -1;
    for (i = 0; i < n; i++) {
        if (strcmp(wk[i].department, "Account") == 0) {
            sum3 = sum3 + wk[i].salary;
            if (max3 < wk[i].salary) {
                max3 = wk[i].salary;
                index3 = i;  // Update the index when a higher salary is found
            }
        }
    }

    if (index3 != -1) {
        printf("\n%d\t", wk[index3].worker_id);
        printf("%s\t", wk[index3].first_name);
        printf("%s\t", wk[index3].last_name);
        printf("%d\t", wk[index3].salary);
        printf("%d-%d-%d\t", wk[index3].j_d.year, wk[index3].j_d.month, wk[index3].j_d.date);
        printf("%s\t", wk[index3].department);
    }

    // Part B:
    printf("\n");
    printf("Total salary in 'HR' department is: %d\n", sum1);
    printf("Total salary in 'Admin' department is: %d\n", sum2);
    printf("Total salary in 'Account' department is: %d\n\n", sum3);
}
