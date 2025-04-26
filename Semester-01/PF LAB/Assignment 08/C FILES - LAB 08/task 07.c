#include <stdio.h>

int main () {
	
	int total_amount, total_visits;
	printf("Enter the total amount of bill: ");
	scanf("%d", &total_amount);
	printf("Enter the total number of visits: ");
	scanf("%d", &total_visits);
	
	calculateDiscount(total_amount, total_visits);
	
	
	
	return 0;
}

	calculateDiscount(int total_amount, int total_visits) {
		int discount;
		if (total_visits > 10 && total_amount >= 50) {
			discount = total_amount * 0.15;
			total_amount -= discount;
		}
		else if (total_visits > 5 && total_amount >= 30) {
			discount = total_amount * 0.10;
			total_amount -= discount;
		}
		else {
		}
		
		printf("The final bill is: %d", total_amount);
	
	}
