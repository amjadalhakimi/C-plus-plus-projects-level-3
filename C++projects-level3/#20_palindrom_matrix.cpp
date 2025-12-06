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
            arr[i][j] = numbers::randomNumber(0, 1);
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

bool isPalindromMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols / 2; j++)
        {
            if (arr[i][j] != arr[i][cols - j - 1])
            {
                return false;
            }
        }
    }
    return true;
}

void PrintResult()
{
    int arr[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 8}};
    // FillArrayWithRandomNumbers(arr, 3, 3);

    cout << "\nMatrix1:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    if (isPalindromMatrix(arr, 3, 3))
    {
        cout << "Yes, matrix is palindrom.\n";
    }
    else
    {
        cout << "No, matrix is NOT palindrom.\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}