#include <iostream>
#include <random>

template<typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    T& get(int row, int col) {
        return data[row][col];
    }

    void set(int row, int col, T value) {
        data[row][col] = value;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    template<typename U>
    Matrix<U> operator*(const Matrix<U>& other) const {
        Matrix<U> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                U sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += static_cast<U>(data[i][k]) * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }
};

int main() {
    // IntMatrix demonstration
    Matrix<int> intMatrix1(2, 2);
    // intMatrix1.set(0, 0, 1);
    // intMatrix1.set(0, 1, 2);
    // intMatrix1.set(1, 0, 3);
    // intMatrix1.set(1, 1, 4);

    

    Matrix<int> intMatrix2(2, 2);
    intMatrix2.set(0, 0, 5);
    intMatrix2.set(0, 1, 6);
    intMatrix2.set(1, 0, 7);
    intMatrix2.set(1, 1, 8);

    std::cout << "IntMatrix 1:" << std::endl;
    intMatrix1.display();
    std::cout << std::endl;

    std::cout << "IntMatrix 2:" << std::endl;
    intMatrix2.display();
    std::cout << std::endl;

    Matrix<int> intMatrixSum = intMatrix1 + intMatrix2;
    std::cout << "IntMatrix Sum:" << std::endl;
    intMatrixSum.display();
    std::cout << std::endl;

    // DoubleMatrix demonstration
    Matrix<double> doubleMatrix1(2, 2);
    doubleMatrix1.set(0, 0, 1.5);
    doubleMatrix1.set(0, 1, 2.5);
    doubleMatrix1.set(1, 0, 3.5);
    doubleMatrix1.set(1, 1, 4.5);

    Matrix<double> doubleMatrix2(2, 2);
    doubleMatrix2.set(0, 0, 5.5);
    doubleMatrix2.set(0, 1, 6.5);
    doubleMatrix2.set(1, 0, 7.5);
    doubleMatrix2.set(1, 1, 8.5);

    std::cout << "DoubleMatrix 1:" << std::endl;
    doubleMatrix1.display();
    std::cout << std::endl;

    std::cout << "DoubleMatrix 2:" << std::endl;
    doubleMatrix2.display();
    std::cout << std::endl;

    Matrix<double> doubleMatrixProduct = doubleMatrix1 * doubleMatrix2;
    std::cout << "DoubleMatrix Product:" << std::endl;
    doubleMatrixProduct.display();

    return 0;
}
