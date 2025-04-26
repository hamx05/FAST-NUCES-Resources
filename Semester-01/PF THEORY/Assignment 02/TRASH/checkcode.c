#include <stdio.h>

int main() {
    int i,j,r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int arr[r][c];

    printf("Enter the binary matrix (0s and 1s):\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int max = 0, maxI = 0, maxJ = 0;

    // Create a new matrix to store the side lengths of square submatrices ending at each cell
    int brr[r][c];

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (i == 0 || j == 0) {
                brr[i][j] = arr[i][j];
            } else if (arr[i][j] == 1) {
                brr[i][j] = 1 + min(brr[i - 1][j], brr[i][j - 1], brr[i - 1][j - 1]);
                if (brr[i][j] > max) {
                    max = brr[i][j];
                    maxI = i;
                    maxJ = j;
                }
            } else {
                brr[i][j] = 0;
            }
        }
    }

    printf("Largest square submatrix of 1s:\n");
    for (i = maxI; i > maxI - max; i--) {
        for (j = maxJ; j > maxJ - max; j--) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Dimension of the largest square matrix (%d x %d)\n", max, max);

    return 0;
}

