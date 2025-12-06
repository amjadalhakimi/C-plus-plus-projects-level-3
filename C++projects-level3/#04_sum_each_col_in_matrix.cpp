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

void PrintSumCols(int arr[3][3], short rows, short cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += arr[j][i];
        }
        cout << "Col " << i + 1 << " sum = " << sum << endl;
        sum = 0;
    }
}

void PrintResult()
{
    int arr[3][3];
    FillArrayWithRandomNumbers(arr, 3, 3);

    cout << "The following is a 3x3 random matrix:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    cout << "\nThe following are the sum of each row in a matrix:\n";
    PrintSumCols(arr, 3, 3);
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}