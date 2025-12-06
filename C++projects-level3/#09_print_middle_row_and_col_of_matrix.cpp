#include <iostream>
#include <iomanip>
#include "Libraries/lib_level3.h"

using namespace std;

void FillArrayWithRandomNumbers(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = numbers::randomNumber(1, 10);
        }
    }
}

void PrintRandom3x3Matrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d   ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

void PrintRandom3x3MatrixMiddleRow(int arr[3][3], short rows, short cols)
{
    short MiddleRow = rows / 2;

    for (int i = 0; i < cols; i++)
    {
        printf("%0*d   ", 2, arr[MiddleRow][i]);
    }
}

void PrintRandom3x3MatrixMiddleCol(int arr[3][3], short rows, short cols)
{
    short MiddleCol = cols / 2;

    for (int i = 0; i < rows; i++)
    {
        printf("%0*d   ", 2, arr[i][MiddleCol]);
    }
}

void PrintResult()
{
    int arr[3][3];
    FillArrayWithRandomNumbers(arr, 3, 3);

    cout << "\nMatrix1:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    cout << "\nMiddle Row of Matrix1 is:\n";
    PrintRandom3x3MatrixMiddleRow(arr, 3, 3);

    cout << "\nMiddle Col of Matrix1 is:\n";
    PrintRandom3x3MatrixMiddleCol(arr, 3, 3);
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}