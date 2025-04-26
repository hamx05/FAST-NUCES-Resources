#include <stdio.h>

int main () {
	
	int i, j, temp_age=100, temp_price=9999;
	int age[10] = {10,20,30,40,50,20,30,10,40,50};
	int price[10] = {1000, 2500, 3300, 4200, 5500, 2200, 3000, 1200, 4500, 5000};
	
	for (i=0; i<10-1; i++) {
		for (j=0; j<10-i-1; j++) {
			if (age[j] > age[j+1]) {
				temp_age = age[j];
				age[j] = age[j+1];
				age[j+1] = temp_age;
			}
			if (price[j] < price[j+1]) {
				temp_price = price[j];
				price[j] = price[j+1];
				price[j+1] = temp_price;
			}
		}
	}
	
	for (i=0; i<10; i++) {
			printf("Shirt for age %d with price %d.\n", age[i], price[i]);
		}
		
	return 0;
}
