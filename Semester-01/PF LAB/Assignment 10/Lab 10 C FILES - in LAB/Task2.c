#include <stdio.h>

int main () {
	int i, j, n,m;
	
	printf("enter the no. of students: ");
	scanf("%d", &n);
	printf("\n");
	int *ptr=((int*) malloc(n*sizeof(int)));
	for(i=0;i<n;i++){
		printf("Enter the roll no. of student %d: ", i+1);
		scanf("%d", &*(ptr+i));
	}
	//Printing first list
	for(i=0;i<n;i++){
		printf("Roll no. of student %d: %d\n",i+1, *(ptr+i));
	}
	
	printf("\n");
	//Reallocating memory for 5 students
	printf("enter the additional no. of students: ");
	scanf("%d", &m);
	ptr=(int*) realloc(ptr,n*sizeof(int));
		for(j=0;j<m;j++){
		printf("Enter the roll no. of student %d: ", i+j+1);
		scanf("%d", &*(ptr+i+j));
	}
	
	//Printing new list
	printf("\nUpdated list:\n");
	for(i=0;i<n+m;i++){
		printf("Roll no. of student %d: %d\n",i+1, *(ptr+i));
	}

}

