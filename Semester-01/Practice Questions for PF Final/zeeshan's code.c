#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,j,k;
	int n=6;
//	char *arr;
//   arr=(char*)malloc(n*sizeof(char)); 

//   if (arr == NULL) { 
//      printf("Memory allocation failed\n");
//      exit(1);
//   }
   	
	char arr[6] = {'h','a', 'm', 'm', 'a', 'd'};
   	
//	printf("Enter the string:");
//	for(i=0;i<n;i++){
//		scanf(" %c",&arr[i]); 
//	}
	for(i=1;i<=n;i++){
		for(k=0;k<=n-i;k++){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf("%c ",arr[j-1]); 
		}
		printf("\n");
	}
	
//   free(arr);
	return 0;
}
