#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sUserData
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0.0;
};



vector<string> SplitString(string text, string delim)
{
    vector<string> vWords;

    string sWord;

    short pos = 0;

    while (((pos = text.find(delim)) != std::string::npos))
    {
        sWord = text.substr(0, pos);
        if (sWord != "")
        {
            vWords.push_back(sWord);
        }

        text.erase(0, pos + delim.length());
    }

    if (text != "")
    {
        vWords.push_back(text);
    }

    return vWords;
}

sUserData SplitStringToStract(string text, string delim = "#//#")
{
    vector<string> Records = SplitString(text, delim);
    sUserData UserData;
    UserData.AccountNumber = Records.at(0);
    UserData.PinCode = Records.at(1);
    UserData.Name = Records.at(2);
    UserData.Phone = Records.at(3);
    UserData.AccountBalance = stof(Records.at(4));

    return UserData;
}

void PrintUserDataStructur(sUserData UserData)
{
    cout << "The following is the extracted data\n\n";
    cout << "Account Number : " << UserData.AccountNumber << endl;
    cout << "PinCode        : " << UserData.PinCode << endl;
    cout << "Name           : " << UserData.Name << endl;
    cout << "Phone          : " << UserData.Phone << endl;
    cout << "Account Balance: " << UserData.AccountBalance << endl;
}

void PrintResult()
{
    string text = "A150#//#1234#//#amjad hakimi#//#078878#//#5000.000000";
    sUserData UserData = SplitStringToStract(text, "#//#");
    PrintUserDataStructur(UserData);
}

int main()
{
    PrintResult();

    return 0;
}