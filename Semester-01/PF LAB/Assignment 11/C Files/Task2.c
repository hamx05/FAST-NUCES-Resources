#include <stdio.h>
#include <string.h>

int main () {
	int j, i,n, valid;
	
	struct Date {
		int day;
		int month;
		int year;
	} ;
	
	
	printf("enter the number of dates you want to enter: ");
	scanf("%d", &n);
	struct Date arr[n];
	for (i=0; i<n; i++) {
	printf("Enter date %d \n", i+1);
	printf("enter the day, month, and year: ");
	scanf("%d %d %d", &arr[i].day, &arr[i].month, &arr[i].year);
	}
	valid=1;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if (arr[i].day != arr[j].day && arr[i].month!=arr[j].month && arr[i].year!=arr[j].year) {
				valid=0;	
			}
		}
	}
	if(valid) {
		printf("date equal");
	}
	else {
		printf("dates unequal");
	}
	
	return 0;
}



