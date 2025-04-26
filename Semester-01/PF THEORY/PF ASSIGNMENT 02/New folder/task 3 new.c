#include <stdio.h>

int main () {
	
	int timeslot[5][2] = { {1, 0},{1, 1},{0, 1},{1, 0},{1, 1} };
    int price[5][2] = { {300, 0},{320, 310},{0, 280},{380, 0},{375, 400} };
	
	printf("Enter your prefered day for the flight:\n1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n5. Friday");
	scanf("%d", &preference_day);
	
	switch (preference_day) {
		case 1:
		case 2:
		case 3:
		case 4:	
		case 5:
			printf("Enter your preference:\nA. Morning\nB. Evening");
			scanf("%d", &preference_time);
			switch (preference_time) {
				case A: // Morning
					for (i=0;i<5;i++) {
						j=0;
						if (timeslot[i][j] == 1) {
							
						}
					}
	}
	
	
	
	
	
	
	printf("Enter your preference for the flight:\n1. Time\n2. Price");
	scanf("%d", &preference);
	switch (preference) {
		case 1:	
			printf("Enter your preference:\nA. Morning\nB. Evening");
			scanf("%d", &preference_time);
			switch (preference_time) {
			case A: // Morning
			for (i=0;i<5;i++) {
				for (j=0;j<2;j++) {
				if (timeslot[i][j] == 1) {
					best_day = i;
					break;
				}
				
			}
		}
		case 2:	
		for (i=0;i<5;i++) {
			for (j=1;j<2;j++) {
				if (timeslot[i][j] == 1 && ) {
					best_day = i;
					break;
				if (min_price > data[i][j]) {
					count
					break;
				}
				
			}
		}
			
	}
	
	
	return 0;
}
