#include <stdio.h>

int main () {
printf("Student ID: 23K-2005\n");
printf("Student Name: Muhammad Hammad\n\n");

	int i, j, k, l, n, sum1, sum2, iCube, jCube, kCube, lCube, nCube;
	
	printf("enter the value of n: ");
	scanf("%d", &n);
	nCube = n * n * n;
	
	for (i=1;i<=n;i++) {
		iCube = i*i*i;
		
		for (j=i;j<=n;j++) {
			jCube = j*j*j;
			sum1 = iCube + jCube;
			
			for (k=i+1;k<=n;k++) {
				kCube= k*k*k;
				
				for (l=k;l<=n;l++) {
					lCube= l*l*l;
					sum2= kCube + lCube;
					
					if (sum1==sum2 && sum1<nCube){
					printf("%d\n", sum1);
						
				}
			}
		}
		
	}	
}
return 0;	
}
