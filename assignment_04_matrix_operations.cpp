// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}
void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}
void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);
}
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    cout << "\nSum of Matrices (A + B):" << endl;
    displayMatrix(result, rows, cols);
}
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, const int matrixB[MAX_SIZE][MAX_SIZE], int rowsB, int colsB) {
    int result[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    cout << "\nProduct of Matrices (A x B):" << endl;
    displayMatrix(result, rowsA, colsB);
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    cout << "=== PART A: Transpose Matrix ===" << endl;
    cout << "Enter number of rows for matrix: ";
    cin >> rowsA;
    cout << "Enter number of columns for matrix: ";
    cin >> colsA;

    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
        cout << "Error: Rows and columns must be between 1 and " << MAX_SIZE << "." << endl;
        return 0;
    }
    readMatrix(matrixA, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrixA, rowsA, colsA);

    cout << "\n=== PART B: Add Two Matrices ===" << endl;
    cout << "Enter number of rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter number of columns for matrix A: ";
    cin >> colsA;

    cout << "Enter Matrix A:" << endl;
    readMatrix(matrixA, rowsA, colsA);

    cout << "Enter Matrix B (same size as A):" << endl;
    readMatrix(matrixB, rowsA, colsA);
    addMatrices(matrixA, matrixB, result, rowsA, colsA);


    cout << "\n=== PART C: Multiply Two Matrices ===" << endl;
    cout << "Matrix A - Enter number of rows: ";
    cin >> rowsA;
    cout << "Matrix A - Enter number of columns: ";
    cin >> colsA;
    cout << "Enter Matrix A:" << endl;
    readMatrix(matrixA, rowsA, colsA);

    cout << "Matrix B - Enter number of rows (must equal columns of A): ";
    cin >> rowsB;
    cout << "Matrix B - Enter number of columns: ";
    cin >> colsB;
    cout << "Enter Matrix B:" << endl;
    readMatrix(matrixB, rowsB, colsB);

    multiplyMatrices(matrixA, rowsA, colsA, matrixB, rowsB, colsB);

    return 0;

}