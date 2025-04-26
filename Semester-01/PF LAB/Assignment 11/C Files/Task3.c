#include <stdio.h>

int main () {
	
	int i,j,n;
	
	typedef struct Employee {
		char name[30];
		int salary;
		int working_hrs;
	} Employee;
	
	Employee employees[10];
	
	printf("enter the number of employees: ");
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		printf("Enter data for employee %d\n", i+1);
		printf("Name: ");
		scanf("%s", &employees[i].name);
		printf("Salary: ");
		scanf("%d", &employees[i].salary);
		printf("Working hours: ");
		scanf("%d", &employees[i].working_hrs);
	}
	
	for (i=0; i<n; i++) {
		if (employees[i].working_hrs > 7 && employees[i].working_hrs <= 9) {
			employees[i].salary += 50;
		}
		
		else if (employees[i].working_hrs > 8 && employees[i].working_hrs <= 10) {
			employees[i].salary += 100;
		}
		
		else if (employees[i].working_hrs > 10 && employees[i].working_hrs <= 12) {
			employees[i].salary += 150;
		}
		else {
		}
	}
	
	printf("\n");
	for (i=0; i<n; i++) {
		printf("Final data for employee %d\n", i+1);
		printf("Name: %s\n", employees[i].name);
		printf("Salary: %d\n", employees[i].salary);
		printf("Working hours: %d\n\n", employees[i].working_hrs);
	}
	
	
	
	return 0;
}