#include <stdio.h>
struct Student{
    int id, quiz1, quiz2, midTerm, finalExam, total;
    char name[50];
};

int main(){
	int i,n;
    FILE *file;
    struct Student students[20];

    file = fopen("student_records.txt", "w");

    if (file == NULL){
        printf("Error opening file for writing.\n");
        exit(1);
    }
   printf("Enter the number of students: ");
   scanf("%d",&n);

    for (i=0; i<n; i++) {
        printf("Enter the records for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Quiz 1 Score: ");
        scanf("%d", &students[i].quiz1);
        printf("Quiz 2 Score: ");
        scanf("%d", &students[i].quiz2);
        printf("Mid-Term Score: ");
        scanf("%d", &students[i].midTerm);
        printf("Final Exam Score: ");
        scanf("%d", &students[i].finalExam);

    
        students[i].total = students[i].quiz1 + students[i].quiz2 + students[i].midTerm + students[i].finalExam;

        fprintf(file, "%d %s %d %d %d %d %d\n", students[i].id, students[i].name,students[i].quiz1, students[i].quiz2,
		                          students[i].midTerm,students[i].finalExam, students[i].total);
 }

    fclose(file);
    file = fopen("student_records.txt", "r");

  if (file == NULL){
        printf("Error opening file for reading.\n");
        exit(1);
  }

int countBelow50 = 0, countBelow80 = 0, countBelow100 = 0;
  while(fscanf(file, "%*d %*s %*d %*d %*d %*d %d", &students[0].total) != EOF){
    if(students[0].total < 50){
            countBelow50++;
        } 
	else if (students[0].total >= 50 && students[0].total < 80){
            countBelow80++;
        } 
	else if (students[0].total >= 80 && students[0].total < 100){
            countBelow100++;
    }
}
    printf("\nStatistical Analysis:\n");
    printf("Number of students with total score below 50: %d\n", countBelow50);
    printf("Number of students with total score below 80: %d\n", countBelow80);
    printf("Number of students with total score below 100: %d\n", countBelow100);

fclose(file);
return 0;
}

