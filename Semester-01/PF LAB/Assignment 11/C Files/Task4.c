#include <stdio.h>


int main() {
	
	typedef struct Employee {
	    int employeeID;
	    char name[50];
	    float salary;
	} Employee;

	typedef struct Organization {
	    char organisationName[50];
	    char organisationNumber[20];
	    Employee emp;
	} Organization;

    Organization org;
    org.emp.employeeID;
    org.emp.name;
    org.emp.salary;

	printf("Enter the Organisation name: ");
	scanf("%s", &org.organisationName);
	printf("Enter the Organisation number: ");
	scanf("%s", &org.organisationNumber);
	printf("Enter the employee ID: ");
	scanf("%d", &org.emp.employeeID);
	printf("Enter the employee name: ");
	scanf("%s", &org.emp.name);
	printf("Enter the employee salary: ");
	scanf("%f", &org.emp.salary);
	printf("\n\n");
	
    printf("The size of structure organization: %zu\n", sizeof(org));
    printf("Organisation Name: %s\n", org.organisationName);
    printf("Organisation Number: %s\n", org.organisationNumber);
    printf("Employee id: %d\n", org.emp.employeeID);
    printf("Employee name: %s\n", org.emp.name);
    printf("Employee Salary: %.2f\n", org.emp.salary);

    return 0;
}

