#include <iostream>
using namespace std;

void PrintFibonacciSeriesRecursion(short count, int pre1 = 0, int pre2 = 1, int current = 1)
{
    if (count > 0)
    {
        cout<<current<<" ";
        
        current = pre1 + pre2;
        pre1 = pre2;
        pre2 = current;

        PrintFibonacciSeriesRecursion(count -1, pre1, pre2, current);
    }  
}


int main()
{
    PrintFibonacciSeriesRecursion(10);
    return 0;
}