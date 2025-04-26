#include <stdio.h>

int main() {
    printf("Student ID: 23K-2005\n");
    printf("Student Name: Muhammad Hammad\n\n");

	int preference;
    int min_price_morning = 999, min_price_evening = 999, count_morning, count_evening, i, j;
    int timeSlot[5][2] = {{1, 0}, {1, 1}, {0, 1}, {1, 0}, {1, 1}};
    int price[5][2] = {{300, 0}, {320, 310}, {0, 280}, {380, 0}, {375, 400}};

    // PART 01: 
    printf("\nPART 01:\n");

    int user_preference;
    printf("Choose your preference:\n");
    printf("1. Time\n");
    printf("2. Price\n");
    printf("Enter your preference (1 for Time, 2 for Price): ");
    scanf("%d", &preference);

    if (preference == 1) {
       
        printf("Available Flights by Time:\n");
        for (i = 0; i < 5; i++) {
            printf("Day: ");
            switch (i) {
                case 0: printf("Monday"); break;
                case 1: printf("Tuesday"); break;
                case 2: printf("Wednesday"); break;
                case 3: printf("Thursday"); break;
                case 4: printf("Friday"); break;
            }
            printf("\n");

            for (j = 0; j < 2; j++) {
                if (timeSlot[i][j] == 1) {
                    printf("  ");
                    switch (j) {
                        case 0: printf("Morning: "); break;
                        case 1: printf("Evening: "); break;
                    }
                    printf("Price: %d\n", price[i][j]);
                }
            }
        }
    } else if (preference == 2) {
        printf("Available Flights by Price:\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 2; j++) {
                if (timeSlot[i][j] == 1) {
                    printf("Day: ");
                    switch (i) {
                        case 0: printf("Monday"); break;
                        case 1: printf("Tuesday"); break;
                        case 2: printf("Wednesday"); break;
                        case 3: printf("Thursday"); break;
                        case 4: printf("Friday"); break;
                    }

                    printf(", ");
                    switch (j) {
                        case 0: printf("Morning"); break;
                        case 1: printf("Evening"); break;
                    }

                    printf(", Price: %d\n", price[i][j]);
                }
            }
        }
    } else {
        printf("Invalid preference choice.\n");
    }

    // PART 02:
    printf("\nPART 02:\n");
    min_price_morning = 999;
    count_morning = 0;
    for (i = 0; i < 5; i++) {
        if (timeSlot[i][0] == 1 && price[i][0] < min_price_morning) {
            min_price_morning = price[i][0];
            count_morning = i;
        }
    }
    printf("Morning flight is available on ");
    switch (count_morning) {
        case 0: printf("Monday"); break;
        case 1: printf("Tuesday"); break;
        case 2: printf("Wednesday"); break;
        case 3: printf("Thursday"); break;
        case 4: printf("Friday"); break;
    }
    printf(" with a price of %d.\n", min_price_morning);

    // PART 03:
    printf("\nPART 03:\n");
    min_price_evening = 999;
    count_evening = 0;
    for (i = 0; i < 5; i++) {
        if (timeSlot[i][1] == 1 && price[i][1] < min_price_evening) {
            min_price_evening = price[i][1];
            count_evening = i;
        }
    }
    printf("Evening flight is available on ");
    switch (count_evening) {
        case 0: printf("Monday"); break;
        case 1: printf("Tuesday"); break;
        case 2: printf("Wednesday"); break;
        case 3: printf("Thursday"); break;
        case 4: printf("Friday"); break;
    }
    printf(" with a price of %d.\n", min_price_evening);

    // PART 04:
    printf("\nPART 04:\n");
    int day;

    printf("Enter the day you want to look for flights (Monday(0) - Friday(4)): ");
    scanf("%d", &day);

    for (j = 0; j < 1; j++) {
        if (timeSlot[day][j] == 1) {
            printf("Morning flight is available with a price of %d\n", price[day][j]);
        } else {
            printf("No morning flight is available.\n");
        }
        if (timeSlot[day][j + 1] == 1) {
            printf("Evening flight is available with a price of %d\n", price[day][j + 1]);
        } else {
            printf("No evening flight is available.\n");
        }
    }

    return 0;
}

