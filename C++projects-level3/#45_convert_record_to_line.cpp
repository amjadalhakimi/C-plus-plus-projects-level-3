#include <iostream>
#include <string>
#include <vector>
#include "Libraries/lib_level3.h"

using namespace std;

struct sUserData
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0.0;
};

float readPositiveNumberFloat(string message)
{
    float num = 0;
    while (num <= 0)
    {
        cout << message;
        cin>>num;
    }

    return num;
}

string ReadText(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);

    return text;
}

void FillUserData(sUserData &UserData)
{
    UserData.AccountNumber = ReadText("Enter Account Number: ");
    UserData.PinCode = ReadText("Enter PinCode: ");
    UserData.Name = ReadText("Enter Name: ");
    UserData.Phone = ReadText("Enter Phone: ");
    UserData.AccountBalance = readPositiveNumberFloat("Enter Account Balance: ");
}

string JoinString(sUserData UserData, string delim)
{
    string text = "";

    text += UserData.AccountNumber + delim;
    text += UserData.PinCode + delim;
    text += UserData.Name + delim;
    text += UserData.Phone + delim;
    text += to_string(UserData.AccountBalance);

    return text;
}

void PrintResult()
{
    sUserData UserData;
    cout << "Please enter clinet data\n\n";
    FillUserData(UserData);
    cout << JoinString(UserData, "#//#") << endl;
}

int main()
{
    PrintResult();

    return 0;
}