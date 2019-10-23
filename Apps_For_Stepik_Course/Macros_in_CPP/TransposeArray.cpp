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
    // for (size_t i = 0; i < a; i++)
    //     delete[] matrix[i];
    delete[] matrix[0];
    delete[] matrix;
}

void fillMatrix(int **matrix, size_t a, size_t b)
{
    for (size_t i = 0; i < a; i++)
        for (size_t j = 0; j < b; j++)
            matrix[i][j] = j;
}

void printMatrix(int **matrix, size_t a, size_t b)
{
    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
            cout << matrix[a][b] << ' ';
        cout << endl;
    }
}

int **transpose(const int *const *m, unsigned rows, unsigned cols)
{
    /* ... */
}

int main()
{
    cout << "enter matrix dimensions A & B: ";
    unsigned a, b;
    cin >> a >> b;
    int **matrix = allocateMatrixQuickly(a, b);
    fillMatrix(matrix, a, b);
    cout << "fillMatrix - OK" << endl;
    printMatrix(matrix, a, b);
    cout << "printMatrix - OK" << endl;
    freeMatrixQuickly(matrix);
    cout << "freeMatrixQuickly - OK" << endl;
    return 0;
}