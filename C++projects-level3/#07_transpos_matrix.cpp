#include <iostream>
#include <iomanip>

using namespace std;

void FillArrayWithOrderedNumbers(int arr[3][3], short rows, short cols)
{
    int coutner = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = coutner++;
        }
    }
}

void FillArrayWithTransposedNumbers(int arr[3][3], short rows, short cols)
{
    int coutner = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[j][i] = coutner++;
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

void PrintResult()
{
    int arr[3][3], arrTransposed[3][3];
    FillArrayWithOrderedNumbers(arr, 3, 3);

    cout << "The following is a 3x3 ordered matrix:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    FillArrayWithTransposedNumbers(arrTransposed, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintRandom3x3Matrix(arrTransposed, 3, 3);
}

int main()
{
    PrintResult();
    
    cout << endl;
    return 0;
}