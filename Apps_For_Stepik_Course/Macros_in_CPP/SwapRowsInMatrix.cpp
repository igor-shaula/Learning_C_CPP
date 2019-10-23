#include <iostream>
using namespace std;

int **allocateMatrixQuickly(size_t a, size_t b)
{
    int **matrix = new int *[a];
    matrix[0] = new int[a * b];
    for (size_t i = 1; i < a; i++)
        matrix[i] = matrix[i - 1] + b;
    return matrix;
}

void freeMatrixQuickly(int **matrix)
{
    delete[] matrix[0];
    delete[] matrix;
}

void fillMatrix(int **matrix, size_t a, size_t b)
{
    for (size_t i = 0; i < a; i++)
        for (size_t j = 0; j < b; j++)
            matrix[i][j] = 50 - i * 10 + j;
}

void printMatrix(int **matrix, size_t a, size_t b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}

unsigned detectMinValueRow(int *m[], unsigned rows, unsigned cols)
{
    int minValue = m[0][0];
    unsigned minRow;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (m[i][j] < minValue)
            {
                minValue = m[i][j];
                minRow = i;
            }
    return minRow;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    unsigned minRow = detectMinValueRow(m, rows, cols);
    cout << "min value row: " << minRow << endl;
    int *tmpRow = new int[rows];
    tmpRow = m[0];
    m[0] = m[minRow];
    m[minRow] = tmpRow;
    delete[] tmpRow;
}

int main()
{
    int **matrix = allocateMatrixQuickly(4, 3);
    cout << "allocateMatrixQuickly" << endl;
    fillMatrix(matrix, 4, 3);
    cout << "matrix created:" << endl;
    printMatrix(matrix, 4, 3);
    swap_min(matrix, 4, 3);
    cout << "matrix modified:" << endl;
    printMatrix(matrix, 4, 3);
    freeMatrixQuickly(matrix);
    cout << "freeMatrixQuickly" << endl;
    return 0;
}