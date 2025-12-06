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
           cout<<arr[i][j]<<" ";
        }
        cout << endl;
    }
}

short CheckNumberFrequency(int arr[3][3], short rows, short cols, short num)
{
    short counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == num)
                counter++;
        }
    }

    return counter;
}

bool CheckSparseMatrix(int arr[3][3], short rows, short cols)
{
    return (CheckNumberFrequency(arr, rows, cols, 0) > (rows * cols) / 2);
}

void PrintResult()
{
    int arr[3][3];
    FillArrayWithRandomNumbers(arr, 3, 3);

    cout << "\nMatrix1:\n";
    PrintRandom3x3Matrix(arr, 3, 3);


    if (CheckSparseMatrix(arr, 3, 3))
    {
        cout << "Yes, matrix is sparse." << endl;
    }
    else
    {
        cout << "No, matrix is NOT sparse." << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}