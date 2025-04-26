#include <stdio.h>

typedef struct Ticket {
	int seatNum;
	char busName[20];
	int price;
	char destCity[20];
	struct Traveller {
		int cnic;
		char name[20];
		int age;
		int contactNo;
	} Traveller;
} Ticket;

	Ticket ticket[5]; // assuming 5 for Mr Patel's family

int main () {
	int i,j,n,totalBill;
	
	printf("Enter the number of tickets you want to purchase: ");
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		printf("\tEnter the details for customer %d\n",i+1);
		printf("Name: ");
		scanf("%s", ticket[i].Traveller.name);
		printf("Age: ");
		scanf("%d", &ticket[i].Traveller.age);
		printf("CNIC ID: ");
		scanf("%d", &ticket[i].Traveller.cnic);
		printf("Contact number: ");
		scanf("%d", &ticket[i].Traveller.contactNo);
		if (ticket[i].Traveller.age < 15 || ticket[i].Traveller.age > 60) {
			ticket[i].price = 4500;
		} else {
			ticket[i].price = 7000;
		}
	}
	
	int priceArray[n];
	for (i=0; i<n; i++) {
		priceArray[i] = ticket[i].price;
	}
	
	totalBill = calculateBill(priceArray,n);
	printf("Total bill: %d", totalBill);
	
	return 0;
}

int calculateBill (int price[], int n) {
	int i, discount=0, totalBill=0;
	
	for (i=0; i<n; i++) {
		totalBill += price[i];	
	}
	
	if (totalBill > 10000) {
		discount = totalBill * 0.1;
		totalBill -= discount;
	}
	else if (totalBill > 25000 && totalBill < 50000) {
		discount = totalBill * 0.20;
		totalBill -= discount;
	}
	else if (totalBill > 50000) {
		discount = totalBill * 0.3;
		totalBill -= discount;
	}
	else {
	}
	
	return totalBill;
}

