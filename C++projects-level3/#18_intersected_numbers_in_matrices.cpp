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

bool isExistsInMatrix(int arr[3][3], short rows, short cols, short num)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == num)
                return true;
        }
    }

    return false;
}

void PrintIntersectedNumbers(int arr[3][3], int arr2[3][3], short rows, short cols)
{
        for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (isExistsInMatrix(arr2, rows, cols, arr[i][j]))
                cout<<arr[i][j]<<" ";
        }
    }
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

    cout<<"\nIntersected Numbers are: \n";
    PrintIntersectedNumbers(arr, arr2, 3, 3);
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}