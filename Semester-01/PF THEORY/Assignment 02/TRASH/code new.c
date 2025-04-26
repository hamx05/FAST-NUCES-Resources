#include <stdio.h>

int main() {
    printf("Student ID: 23K-2005\n");
    printf("Student Name: Muhammad Hammad\n\n");

    int preference;
    int min_price_morning = 999, min_price_evening = 999, count_morning, count_evening, i, j;
    int timeSlot[5][2] = {{1, 0}, {1, 1}, {0, 1}, {1, 0}, {1, 1}};
    int price[5][2] = {{300, 0}, {320, 310}, {0, 280}, {380, 0}, {375, 400}};

    // PART 01: Determine the best day and time slot based on user preferences.
    printf("\nPART 01:\n");
    int preferred_time, preferred_price;


    printf("Enter your preference (Time(0) or Price(1): ");
    scanf("%d", &preference);
    
    switch (preference) {
        case 0:
        printf("Enter your choice (MorningA - EveningB): ");
            case 'A':
            for (i=0;i<5;i++) {
                j=0;
                printf("Morning flight is available for day %d with price %d", i+1, price[i][j]);
                break;
            
            }
            case 'B':
            for (j=0;j<5;j++) {
                i=0;
                printf("%d", timeSlot[i][j]);
                break;
            }
            break;
        case 1:
        min_price_morning = 999;
        count_morning = 0;
        for (i = 0; i < 5; i++) {
        if (timeSlot[i][0] == 1 && price[i][0] < min_price_morning) {
            min_price_morning = price[i][0];
            count_morning = i;
            break;
        }
    }
        
    }
    
   
    

    // PART 02: Determine the morning flight with the lowest price.
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

    // PART 03: Determine the evening flight with the lowest price.
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

    // PART 04: Check availability for a specific day entered by the user.
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
