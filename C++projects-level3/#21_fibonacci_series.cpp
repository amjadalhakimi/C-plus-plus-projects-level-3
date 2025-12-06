#include <iostream>
using namespace std;

void PrintFibonacciSeries(short count)
{
    int pre1 = 0, pre2 = 1, current = 1;

    for (short i = 1; i <= count; i++)
    {
        
        cout<<current<<" ";

        current = pre1 + pre2;
        pre1 = pre2;
        pre2 = current;
        
    }
    cout<<endl; 
    
}

int main()
{
    PrintFibonacciSeries(10);
    return 0;
}