#include <stdio.h>

#define M 3 
#define N 4 

int countOnes(int arr[M][N], int row, int col) {
    int nextRow, nextCol;
    
    if (row == M)
        return 0;

    int currentCount=0;
    
    if (arr[row][col] == 1) {
    	currentCount++;
	}

    if (col == N - 1) {
    nextRow = row + 1;
    nextCol = 0;
	} else {
    nextRow = row;
    nextCol = col + 1;
}
    
    return currentCount + countOnes(arr, nextRow, nextCol);
}

int main() {
    int array[3][4] = {
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int onesCount = countOnes(array, 0, 0);

    printf("Number of 1s in the 2D array: %d\n", onesCount);

    return 0;
}

