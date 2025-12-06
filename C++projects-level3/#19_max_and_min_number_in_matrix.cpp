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
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

short MaxNumberInMatrix(int arr[3][3], short rows, short cols)
{
    short max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
        }
    }

    return max;
}

short MinNumberInMatrix(int arr[3][3], short rows, short cols)
{
    short min = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (min > arr[i][j])
            {
                min = arr[i][j];
            }
        }
    }

    return min;
}

void PrintResult()
{
    int arr[3][3];
    FillArrayWithRandomNumbers(arr, 3, 3);

    cout << "\nMatrix1:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    cout << "\nMaximum number in the matrix is: " << MaxNumberInMatrix(arr, 3, 3);
    cout << "\nMinimum number in the matrix is: " << MinNumberInMatrix(arr, 3, 3);
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}