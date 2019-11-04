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
            matrix[i][j] = i * 10 + j;
}

void printMatrix(int **matrix, size_t a, size_t b)
{
    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}

int **transpose(const int *const *m, unsigned rows, unsigned cols)
{
    int **newMatrix = allocateMatrixQuickly(cols, rows);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newMatrix[j][i] = m[i][j];
    return newMatrix;
}

int main()
{
    cout << "enter matrix dimensions A & B: ";
    unsigned a, b;
    cin >> a >> b;
    int **matrix = allocateMatrixQuickly(a, b);
    cout << "allocateMatrixQuickly - OK" << endl;
    fillMatrix(matrix, a, b);
    cout << "fillMatrix - OK" << endl;
    cout << "initial matrix is:" << endl;
    printMatrix(matrix, a, b);
    int **newMatrix = transpose(matrix, a, b);
    cout << "transposed matrix is:" << endl;
    printMatrix(newMatrix, a, b);
    cout << "printMatrix - OK" << endl;
    freeMatrixQuickly(newMatrix);
    freeMatrixQuickly(matrix);
    cout << "freeMatrixQuickly - OK" << endl;
    return 0;
}