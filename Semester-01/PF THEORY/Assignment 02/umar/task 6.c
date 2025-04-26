#include<stdio.h>
int main(){
	int arr[7]= {1,8,10,12,7,4,3},i,j;
	int totalpairs =0;
	int x=11;
	for(i=0;i<=7;i++){
		for(j=i+1;j<=7;j++){
			if(arr[i]+arr[j]==x){
				totalpairs++;
		//		printf("pair:(%d,%d)\n" ,arr[i],arr[j]);
			}
	}	printf("pair:(%d,%d)\n" ,arr[i],arr[j]);
	}
	
	
	return 0;
}
