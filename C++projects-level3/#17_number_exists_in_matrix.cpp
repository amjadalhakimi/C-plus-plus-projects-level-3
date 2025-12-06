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
            arr[i][j] = numbers::randomNumber(0, 9);
        }
    }
}

void PrintRandom3x3Matrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) <<arr[i][j] << " ";
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

void PrintResult()
{
    int arr[3][3], number = 0;
    number = numbers::readPositiveNumber("Please enter a number to check exists in a matrix: ");
    FillArrayWithRandomNumbers(arr, 3, 3);

    cout << "\nMatrix1:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    if (isExistsInMatrix(arr, 3, 3, number))
    {
        cout << "Yes, it exists in the matrix." << endl;
    }
    else
    {
        cout << "No, it does NOT exists in the matrix." << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    PrintResult();

    cout << endl;
    return 0;
}