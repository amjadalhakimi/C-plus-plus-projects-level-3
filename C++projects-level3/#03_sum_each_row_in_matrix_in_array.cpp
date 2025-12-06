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
            arr[i][j] = numbers::randomNumber(1, 100);
        }
    }
}

void PrintRandom3x3Matrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void FillArrayWithSumRows(int arr[3][3], short rows, short cols, int arr2[3])
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }
        arr2[i] = sum;
        sum = 0;
    }
}

void PrintArray(int arr[3], short rows)
{
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

void PrintResult()
{
    int arr[3][3], rowSum[3];

    FillArrayWithRandomNumbers(arr, 3, 3);
    FillArrayWithSumRows(arr, 3, 3, rowSum);

    cout << "The following is a 3x3 random matrix:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    cout << "\nThe following are the sum of each row in a matrix:\n";
    PrintArray(rowSum, 3);
    // arrayes::printArray(rowSum, 3);
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}