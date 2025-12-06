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

int SumOfMatrix(int arr[3][3], short rows, short cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
    }

    return sum;
}

void PrintResult()
{
    int arr[3][3], arr2[3][3];
    FillArrayWithRandomNumbers(arr, 3, 3);
    FillArrayWithRandomNumbers(arr2, 3, 3);

    cout << "\nMatrix1:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    cout << "\nMatrix2:\n";
    PrintRandom3x3Matrix(arr2, 3, 3);

    if (SumOfMatrix(arr, 3, 3) == SumOfMatrix(arr2, 3, 3))
    {
        cout << "Yes, matrices are equal." << endl;
    }
    else
    {
        cout << "No, matrices are NOT equal." << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}