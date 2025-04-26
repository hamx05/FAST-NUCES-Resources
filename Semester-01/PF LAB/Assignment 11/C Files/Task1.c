#include <stdio.h>
#include <stdlib.h>

int main () {
	int n, i, j, findYear, findRollNo, found;
	
	typedef struct students {
		int roll_no;
		char name[30];
		char dept[30];
		char course[30];
		int joining_year;
	} students;

	students arr[450];
	
	printf("enter the number of students you want to enter the data for: ");
	scanf("%d", &n);
	for (i=0; i<n; i++) {	
		printf("enter the data for student %d:\n", i+1);
		printf("Name: ");
		scanf("%s", arr[i].name);
		printf("Roll no: ");
		scanf("%d", &arr[i].roll_no);
		printf("Department: ");
		scanf("%s", arr[i].dept);
		printf("Course: ");
		scanf("%s", arr[i].course);
		printf("Joining year: ");
		scanf("%d", &arr[i].joining_year);
	}

	printf("\nenter the year you want to filter: ");
	scanf("%d", &findYear);
	
	
	printf("Result:\n");
	found=0;
	for (i=0; i<n; i++) {
		if (arr[i].joining_year == findYear) {
			printf("Name of student %d: %s\n", i+1, arr[i].name);
			found++;
		}
		else if (found==0){
			printf("No student found with year of joining %d", findYear);
		}
	}
	
	printf("\nenter the roll no. you want to filter: ");
	scanf("%d", &findRollNo);
	
	found=0;
	for (i=0; i<n; i++) {
		if (arr[i].roll_no == findRollNo) {
			printf("Result:\n");
			printf("Name of student: %s\n", arr[i].name); 
			found++;
		}
		else if (found==0) {
			printf("No student found with roll no %d", findRollNo);
		}
		else {
		}
	}
	
	return 0;
}
