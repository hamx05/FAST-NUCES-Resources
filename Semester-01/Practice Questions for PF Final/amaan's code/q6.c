#include <stdio.h>
#define MAXROW 3
#define MAXCOL 4
/*User Define Function to Read Matrix*/
void readMatrix(int m[][MAXCOL],int row,int col)
{
int i,j;
for(i=0;i< row;i++)
{
for(j=0;j< col;j++)
{
printf("Enter element [%d,%d] : ",i+1,j+1);
scanf("%d",&m[i][j]);
}
}
}
/*User Define Function to Read Matrix*/
void printMatrix(int m[][MAXCOL],int row,int col)
{
int i,j;
for(i=0;i< row;i++)
{
for(j=0;j< col;j++)
{
printf("%d\t",m[i][j]);
}
printf("\n");
}
}
int main()
{
int a[MAXROW][MAXCOL],b[MAXROW][MAXCOL],result[MAXROW][MAXCOL];
int i,j,r1,c1,r2,c2,sum,avg,transpose[10][10];
printf("Enter number of Rows of matrix a: ");
scanf("%d",&r1);
printf("Enter number of Cols of matrix a: ");
scanf("%d",&c1);
printf("\nEnter elements of matrix a: \n");
readMatrix(a,r1,c1);
// SECOND MATRIX
printf("Enter number of Rows of matrix b: ");
scanf("%d",&r2);
printf("Enter number of Cols of matrix b: ");
scanf("%d",&c2);
printf("\nEnter elements of matrix b: \n");
readMatrix(b,r2,c2);
// TRANSPOSE OF A MATRIX
// computing the transpose
for (i = 0; i < r2; ++i)
for (j = 0; j < c2; ++j) {
transpose[j][i] = b[i][j];
}
// printing the transpose
printf("\nTranspose of the matrix:\n");
for (i = 0; i < c2; ++i)
for (j= 0; j < r2; ++j) {
printf("%d ", transpose[i][j]);
if (j == r2 - 1)
printf("\n");
}
/*sum and sub of Matrices*/
if(r1==r2 && c1==c2)
{
/*Adding two matrices a and b, and result storing in matrix result*/
for(i=0;i< r1;i++)
{
for(j=0;j<c1;j++)
{
result[i][j]=a[i][j]+b[i][j];
}
}
/*print matrix*/
printf("\nMatrix after adding (result matrix):\n");
printMatrix(result,r1,c1);
// ADDING ALL ELMENETS
int sum;
sum=0;
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
sum += result[i][j];
}
}
printf("\nSUM of all elements : %d \n",sum);
avg = sum/12;
printf("\nAverage of all elements : %d \n",avg);
if (avg>=15)
printf("Abnormal Situation");
else
printf("Normal Situation");
}
else
{
printf("\nMatrix can’t be added, Number of Rows & Cols are Different");
}
return 0;
}
