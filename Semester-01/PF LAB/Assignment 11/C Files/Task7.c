#include <stdio.h>
#include <string.h>

int main () {
	
	struct Register {
		char courseID[10];
		char courseName[30];
	};
	
	struct Student { 
		char studentID[10];
		char firstName[15];
		char lastName[15];
		int cellNo;
		char email[40];
		struct Register;
	};
	
	struct Register reg[5];
	struct Student std[5];
	int i;
	
	for (i=0; i<2; i++) {
		printf("Enter the data for Student %d:\n", i+1);
		printf("Student ID: \n");
		scanf("%s", &std[i].studentID);
		printf("First and last name: \n");
		scanf("%s %s", &std[i].firstName, &std[i].lastName);
		printf("Cellphone number: \n");
		scanf("%d", &std[i].cellNo);
		printf("Email: \n");
		scanf("%s", &std[i].email);
		printf("Course ID: \n");
		scanf("%s", &reg[i].courseID);
		printf("Course name: \n");
		scanf("%s", &reg[i].courseName);
		printf("\n");
	}
	printf("\n\n");
	
	for (i=0; i<2; i++) {
		printf("Data of Student %d:\n", i+1);
		printf("Student ID: %s\n", std[i].studentID);
		printf("First and last name: %s %s\n", std[i].firstName, std[i].lastName);
		printf("Cellphone number: %d\n", std[i].cellNo);
		printf("Email: %s\n", std[i].email);
		printf("Course ID: %s\n", reg[i].courseID);
		printf("Course name: %s\n\n", reg[i].courseName);
	}
	return 0;
}
