#include <stdio.h>

int main () {
	
	int car_no, day;
	
		printf("enter the car no: ");
		scanf("%d", &car_no);
		printf("enter the day: ");
		scanf("%d", &day);
		decideCarUsage (car_no, day);
	return 0;
}

void decideCarUsage (int car_no, int day) {
	if (day%2==0 && car_no%2==0 || day%2==1 && car_no%2==1){
			printf("Yes, you can use this car.");
		}
		else {
			printf("No, you cannot use this car.");
		}
}

