#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H

void multiply2DMatrix (int matrix1[2][2], int matrix2[2][2], int resultantMatrix[2][2]) {

    resultantMatrix[0][0] = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0];
    resultantMatrix[0][1] = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1];
    resultantMatrix[1][0] = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0];
    resultantMatrix[1][1] = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1];
}

#endif