#include <stdio.h>

int main () {
	/*I am assuming 3 branches and 3 mobile phones, that's why [3][3]*/
	int i, j, branches, mobiles, bill[3][3] , total_bill, max_total_bill=0, max_bill_branchID, max_bill_mobileID, max_phone_bill;
	
	printf("enter the total number of branches: ");
	scanf("%d", &branches);
	printf("enter the total number of mobile phones: ");
	scanf("%d", &mobiles);
	for (i=0; i<branches; i++) {
		for (j=0; j<mobiles; j++) {
		printf("enter the phone bill for branch ID %d and mobile ID %d: ", i+1, j+1);
		scanf("%d", &bill[i][j]);
		}
	}
	
	// Total bill for each branches
	printf("\n"); 
	for (i=0; i<branches; i++) {
		total_bill = 0;
		for (j=0; j<mobiles; j++) {
			total_bill += bill[i][j];	
		}
		printf("Total bill for branch %d: %d\n", i+1, total_bill);
	
	}
	
	// Total bill for all branches
	total_bill = 0; 
	for (i=0; i<branches; i++) {
		for (j=0; j<mobiles; j++) {
			total_bill += bill[i][j];
		}
	}
		printf("Total bill for all branches: %d", total_bill);
	
	// Branch ID where max bill 
	printf("\n");
	for (i=0; i<branches; i++) {
		total_bill = 0; 
		for (j=0; j<mobiles; j++) {
			total_bill += bill[i][j];	
//			if (max_bill < total_bill) {
//			max_bill = total_bill;
//			max_bill_branchID = i + 1;
//			}
		}
			if (max_total_bill < total_bill) {
			max_total_bill = total_bill;
			max_bill_branchID = i + 1;
			}
	}
	printf("Maximum total bill reported at branch ID %d: %d\n", max_bill_branchID, max_total_bill);
	
	// Branch and Mobile Phone IDs where bill is highest of all mobile phones.
	max_phone_bill = 0;
	for (i=0; i<branches; i++) {
		total_bill = 0; 
		for (j=0; j<mobiles; j++) {
			if (max_phone_bill < bill[i][j]) {
			max_phone_bill = bill[i][j];
			max_bill_branchID = i + 1;
			max_bill_mobileID = j + 1;
			}
		}
		
	}
	printf("Maximum phone bill reported at branch ID %d & mobile phone ID %d:  %d", max_bill_branchID, max_bill_mobileID, max_phone_bill);
	
	return 0;
}
