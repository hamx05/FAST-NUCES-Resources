#include <stdio.h>

int main() {
printf("Student ID: 23K-2005\n");
printf("Student Name: Muhammad Hammad\n\n");

    int r,c,i,j;
    printf("enter the no of rows : ");
    scanf("%d", &r); //  6 rows
    printf("enter the no of columns: ");
    scanf("%d", &c); // 6 columns
    
    int arr[r][c];
    printf("enter the binary matrix :\n");
    for (i=0;i<r;i++) {
        for (j=0;j<c;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int max=0, Lline , lastc;  
    int brr[r][c];
    for (i=0;i<r;i++) {
        brr[i][0] = arr[i][0];
    }
    for (j=0;j<c;j++) {
        brr[0][j] = arr[0][j];
    }
    for (i=1;i<r;i++)
	{
        for (j=1;j<c;j++) 
		{
            if (arr[i][j] == 1)
			 {
               if (brr[i-1][j]<brr[i][j-1]) 
			   {
                    if (brr[i-1][j]<brr[i-1][j-1])
					 {
                        brr[i][j]=brr[i-1][j]+1;
                    } 
					else
					 {
                        brr[i][j]=brr[i-1][j-1]+1;
                    }
                } 
				
                  else if (brr[i][j-1]<brr[i-1][j-1]) 
					{
                        brr[i][j]=brr[i][j-1]+1;
                    } 
					else 
					{
                        brr[i][j]=brr[i-1][j-1]+1;
                    }
                if (brr[i][j]>max) {
                    max=brr[i][j];
                    Lline=i;
                    lastc=j;
                }
            }
			 else {
                brr[i][j] = 0;
            }
        }
    }

    printf("Largest square submatrix of 1s:\n");
    for (i=Lline;i>Lline-max;i--) {
        for (j=lastc;j>lastc-max;j--) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Dimension of largest square matrix (%d x %d)\n", max, max);

    return 0;
}

