#include <stdio.h>

int main() {
    int n;

    struct Date {
        int day;
        int month;
        int year;
    };
    
    struct Date date;
    printf("Enter the current date (day, month, & year):\n");
    scanf("%d %d %d", &date.day, &date.month, &date.year);

    date.day += 45;

    while (date.day > 30) {
        date.month++;
        date.day -= 30;
    }

    while (date.month > 12) {
        date.year++;
        date.month -= 12;
    }

    printf("Final date after adding 45 days:\n");
    printf("%d/%d/%d", date.day, date.month, date.year);

    return 0;
}

