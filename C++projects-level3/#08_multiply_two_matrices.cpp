#include <iostream>
#include <iomanip>
#include "Libraries/lib_level3.h"

using namespace std;

void FillArrayWithOrderedNumbers(int arr[3][3], short rows, short cols)
{
    int coutner = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = numbers::randomNumber(1, 9);
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

void MultipliedRandom3x3Matrix(int arr[3][3], int arr2[3][3], int arrResults[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arrResults[i][j] = arr[i][j] * arr2[i][j];
        }
    }
}

void PrintResult()
{
    int arr[3][3], arr2[3][3], arrResults[3][3];
    FillArrayWithOrderedNumbers(arr, 3, 3);
    FillArrayWithOrderedNumbers(arr2, 3, 3);

    cout << "Matrix 1" << endl;
    PrintRandom3x3Matrix(arr, 3, 3);

    cout << "\nMatrix 2" << endl;
    PrintRandom3x3Matrix(arr2, 3, 3);

    cout << "\nResults:\n";
    MultipliedRandom3x3Matrix(arr, arr2, arrResults, 3, 3);
    PrintRandom3x3Matrix(arrResults, 3, 3);
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}