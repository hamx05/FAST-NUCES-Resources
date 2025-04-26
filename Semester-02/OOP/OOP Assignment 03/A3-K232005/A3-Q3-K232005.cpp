#include <iostream>
#include <random>
using namespace std;

template<typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows];
        for (int i=0; i<rows; i++) {
            data[i] = new T[cols];
        }
    }

    // ~Matrix() {
    //     for (int i=0; i<rows; i++) {
    //         delete[] data[i];
    //     }
    //     delete[] data;
    // }

    T& getMatrix(int row, int col) {
        return data[row][col];
    }

    void setMatrix(int row, int col, T value) {
        data[row][col] = value;
    }

    void displayMatrix() {
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix<T> operator+(const  Matrix<T> &matrix2) const  {
        if (rows != matrix2.rows || cols != matrix2.cols) {
            cout<<"Matrices must have the same dimensions for addition.";
        }
        else {
            Matrix<T> resultantMatrix(rows, cols);
            for (int i=0; i<rows; i++) {
                for (int j=0; j<cols; j++) {
                    resultantMatrix.data[i][j] = data[i][j] + matrix2.data[i][j];
                }
            }
            // resultantMatrix.displayMatrix();
            return resultantMatrix;
        }
    }

    Matrix<T> operator-(Matrix<T> &matrix2) {
        if (rows != matrix2.rows || cols != matrix2.cols) {
            cout<<"Matrices must have the same dimensions for subtraction.";
        }
        else {
            Matrix<T> resultantMatrix(rows, cols);
            for (int i=0; i<rows; i++) {
                for (int j=0; j<cols; j++) {
                    resultantMatrix.data[i][j] = data[i][j] - matrix2.data[i][j];
                }
            }
            return resultantMatrix;
        }
    }

    template<typename U>
    Matrix<U> operator*(Matrix<U> &matrix2) {
        if (cols != matrix2.rows) {
            cout<<"Matrices cannot be multiplied because they don't have the same number of rows and columns.";
        }
        else {
            Matrix<U> resultantMatrix(rows, matrix2.cols);
            for (int i=0; i<rows; i++) {
                for (int j=0; j<matrix2.cols; j++) {
                    U sum = 0;
                    for (int k=0; k<cols; k++) {
                        sum += static_cast<U>(data[i][k]) * matrix2.data[k][j];
                    }
                    resultantMatrix.data[i][j] = sum;
                }
            }
            return resultantMatrix;
        }
    }
};

int main() {

    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout<<"Name: Muhammad Hammad" << endl;
    cout<<"Roll No: 23K-2005" << endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~" << endl;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Int Matrices Declaration  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    
    Matrix<int> intMatrix1(2, 2);
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            intMatrix1.setMatrix(i,j,(rand() % 100 + 1));
        }
    }
    
    Matrix<int> intMatrix2(2, 2);
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            intMatrix2.setMatrix(i,j,(rand() % 100 + 1));
        }
    }
    
    cout<< endl <<"============================"  << endl;
    cout<<"IntMatrix 1:" << endl;
    intMatrix1.displayMatrix();
    cout<<endl;

    cout<<"IntMatrix 2:" << endl;
    intMatrix2.displayMatrix();
    cout<<endl;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Int Matrices Operations  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Matrix<int> intMatrixSum = intMatrix1 + intMatrix2;
    cout<<"IntMatrix Sum:" << endl;
    intMatrixSum.displayMatrix();
    cout<<endl;

    Matrix<int> intMatrixDifference = intMatrix1 - intMatrix2;
    cout<<"IntMatrix Difference:" << endl;
    intMatrixDifference.displayMatrix();
    cout<<endl;

    Matrix<int> intMatrixProduct = intMatrix1 * intMatrix2;
    cout<<"IntMatrix Product:" << endl;
    intMatrixProduct.displayMatrix();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Double Matrices Declaration  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    
    Matrix<double> doubleMatrix1(2, 2);
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            doubleMatrix1.setMatrix(i,j,(rand() % 100 + 1));
        }
    }

    Matrix<double> doubleMatrix2(2, 2);
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            doubleMatrix2.setMatrix(i,j,(rand() % 100 + 1));
        }
    }
    
    cout<<"============================"  << endl;
    cout << "DoubleMatrix 1:" << endl;
    doubleMatrix1.displayMatrix();
    cout << endl;

    cout << "DoubleMatrix 2:" << endl;
    doubleMatrix2.displayMatrix();
    cout << endl;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Double Matrices Operations  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    
    Matrix<double> doubleMatrixSum = doubleMatrix1 + doubleMatrix2;
    cout << "DoubleMatrix Sum:" << endl;
    doubleMatrixSum.displayMatrix();
    cout<<endl;

    Matrix<double> doubleMatrixDifference = doubleMatrix1 - doubleMatrix2;
    cout << "DoubleMatrix Difference:" << endl;
    doubleMatrixDifference.displayMatrix();
    cout<<endl;

    Matrix<double> doubleMatrixProduct = doubleMatrix1 * doubleMatrix2;
    cout << "DoubleMatrix Product:" << endl;
    doubleMatrixProduct.displayMatrix();
    cout<<"============================"  << endl;

    return 0;
}
