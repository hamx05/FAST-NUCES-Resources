#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int rollNo;
	char name[50];
	char department[50];
	int batch;
	char section;
	float cgpa;
};

int main() {
	FILE *file = fopen("student_data.txt", "w");
	struct Student students[100];

	if (file == NULL) {
    	printf("Error opening file for writing.\n");
    	exit(1);
	}

  int n;
	printf("Enter the number of students: ");
	scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
	    printf("Enter data for student %d:\n", i + 1);
	    printf("Roll No: ");
	    scanf("%d", &students[i].rollNo);
	    printf("Name: ");
	    scanf("%s", students[i].name);
	    printf("Department: ");
	    scanf("%s", students[i].department);
	    printf("Batch: ");
	    scanf("%d", &students[i].batch);
	    printf("Section: ");
	    scanf(" %c", &students[i].section);
	    printf("CGPA: ");
	    scanf("%f", &students[i].cgpa);

    	fprintf(file, "%d %s %s %d %c %.2f\n", students[i].rollNo, students[i].name, students[i].department,
        students[i].batch, students[i].section, students[i].cgpa);
  	}

	fclose(file);

	file = fopen("student_data.txt", "r");

	if (file == NULL) {
    	printf("Error opening file for reading.\n");
    	exit(1);
	}

	int searchRollNo, found = 0;
	printf("\nEnter RollNo to search: ");
	scanf("%d", &searchRollNo);

	while (fscanf(file, "%d %s %s %d %c %f", &students[0].rollNo, students[0].name, students[0].department,
		&students[0].batch, &students[0].section, &students[0].cgpa) != EOF) {
    	if (students[0].rollNo == searchRollNo) {
    		printf("\nStudent Found!\n");
    		printf("Roll No: %d\nName: %s\nDepartment: %s\nBatch: %d\nSection: %c\nCGPA: %.2f\n",
            students[0].rollNo, students[0].name, students[0].department,
            students[0].batch, students[0].section, students[0].cgpa);
      		found = 1;
      		break;
    	}
	}

    if (!found) {
    	printf("\nStudent not found with RollNo %d\n", searchRollNo);
	}

	fseek(file, 0, SEEK_SET);
	printf("\nStudents in Batch 2023:\n");

	while (fscanf(file, "%d %s %s %d %c %f", &students[0].rollNo, students[0].name, students[0].department,
        &students[0].batch, &students[0].section, &students[0].cgpa) != EOF) {
    	if (students[0].batch == 2023) {
      		printf("\nRoll No: %d\nName: %s\nDepartment: %s\nBatch: %d\nSection: %c\nCGPA: %.2f\n",
            students[0].rollNo, students[0].name, students[0].department,
            students[0].batch, students[0].section, students[0].cgpa);
    	}
	}

	fclose(file);

	return 0;
}

