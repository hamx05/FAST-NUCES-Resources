#include <stdio.h>

int main () {
printf("Student ID: 23K-2005\n");
printf("Student Name: Muhammad Hammad\n\n");
	
	int min_price=999, count, i, j, day;
	int timeSlot[5][2] = { {1, 0},{1, 1},{0, 1},{1, 0},{1, 1} };
    int price[5][2] = { {300, 0},{320, 310},{0, 280},{380, 0},{375, 400} };

//=======================================================================================
// PART 02:
printf("\n\nPART 02:\n");
	for (i=0;i<5;i++) {
		j=0;
		if (timeSlot[i][j] == 1 && price[i][j] < min_price) {
			min_price = price[i][j];
			count=i;
		}
	}
	printf("Morning flight is available on ");
	switch (count) {
		case 0: printf("Monday"); break;
        case 1: printf("Tuesday"); break;
        case 2: printf("Wednesday"); break;
        case 3: printf("Thursday"); break;
        case 4: printf("Friday"); break;
	}
	printf(" with price %d.", min_price);
	
//=======================================================================================
// PART 03:
printf("\n\nPART 03:\n");
	min_price=999;
	count=0;
	for (i=0;i<5;i++) {
		j=1;
		if (timeSlot[i][j] == 1 && price[i][j] < min_price) {
			min_price = price[i][j];
			count=i;
		}
	}
	printf("Evening flight is available on ");
	switch (count) {
		case 0: printf("Monday"); break;
        case 1: printf("Tuesday"); break;
        case 2: printf("Wednesday"); break;
        case 3: printf("Thursday"); break;
        case 4: printf("Friday"); break;
	}
	printf(" with price %d.", min_price);
	
//=======================================================================================
// PART 04:
printf("\n\nPART 04:\n");
	printf("Enter the day you want to look the flights for: [Monday(0) - Friday(4)]: ");
	scanf("%d", &day);
	
	for (j=0; j<1; j++) {
		if (timeSlot[day][j] == 1) {
			printf("Morning flight is avaiable with price %d\n", price[day][j]);
		}
		else {
			printf("No flight is available for Morning.\n");
		}
		if (timeSlot[day][j+1] == 1) {
			printf("Evening flight is avaiable with price %d\n", price[day][j+1]);
		}
		else {
			printf("No flight is available for Evening.\n");
		}	
	}
//=======================================================================================

return 0;
}
