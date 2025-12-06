#include <iostream>
#include <iomanip>

using namespace std;

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

bool CheckIdentityMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if((i==j && arr[i][j] != 1) || (i!=j && arr[i][j] != 0))
                return false;
        }
    }

    return true;
}

void PrintResult()
{
    int arr[3][3] = {{1,0,0},{0,1,0},{0,0,1}};

    cout << "\nMatrix1:\n";
    PrintRandom3x3Matrix(arr, 3, 3);

    if (CheckIdentityMatrix(arr, 3, 3))
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