#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

string ReadText(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);

    return text;
}

char ReadCharacter(string message)
{
    char letter = ' ';
    cout << message;
    cin >> letter;

    return letter;
}

struct sClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0.0;
};

void LoadDataFromFileToVector(string FileName, vector<string> &vContent)
{
    fstream myFile;

    myFile.open(FileName, ios::in);

    if (myFile.is_open())
    {
        string Line;
        while (getline(myFile, Line))
        {
            vContent.push_back(Line);
        }

        myFile.close();
    }
}

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

sClient SplitStringToStract(string text, string delim = "#//#")
{
    vector<string> Records = SplitString(text, delim);

    sClient Client;
    Client.AccountNumber = Records.at(0);
    Client.PinCode = Records.at(1);
    Client.Name = Records.at(2);
    Client.Phone = Records.at(3);
    Client.AccountBalance = stof(Records.at(4));

    return Client;
}

void PrintClientData(sClient Client)
{
    cout << "\nThe following is the client details:\n\n";
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "PinCode        : " << Client.PinCode << endl;
    cout << "Name           : " << Client.Name << endl;
    cout << "Phone          : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
}

void SaveVetorToFile(string FileName, vector <string> vClients){

    fstream myFile;

    myFile.open(FileName, ios::out);

    if(myFile.is_open()){
        for(string &Clients: vClients){
            if(Clients != "")
                myFile<<Clients<<"\n";
        }
        myFile.close();
    }

}

sClient ReadNewClient(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;
    cout << "Enter PinCode: ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name: ";
    getline(cin, Client.Name);
    cout << "Enter Phone: ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(sClient Client, string delim = "#//#")
{
    string Line = "";

    Line += Client.AccountNumber + delim;
    Line += Client.PinCode + delim;
    Line += Client.Name + delim;
    Line += Client.Phone + delim;
    Line += to_string(Client.AccountBalance);

    return Line;
}

void UpdateClient(vector <string> vClients, string Client, string AccountNumber)
{
    char MakeSure = ReadCharacter("\nAre you sure you want to Update this client (y,n): ");

    if (tolower(MakeSure) == 'y')
    {
        for (string &Line : vClients)
        {
            if (Line == Client)
            {
                Line = ConvertRecordToLine(ReadNewClient(AccountNumber));
                break;
            }
        }

        SaveVetorToFile(ClientsFileName, vClients);
        cout << "\nClient Updated Successfully!\n";
    }
}

void UpdateClientIfExists()
{
    string AccountNumber = ReadText("Please enter account number: ");
    vector<string> vClients;
    sClient ClientData;

    LoadDataFromFileToVector(ClientsFileName, vClients);
    for (string &Client : vClients)
    {
        ClientData = SplitStringToStract(Client);
        if (ClientData.AccountNumber == AccountNumber)
        {
            PrintClientData(ClientData);
            UpdateClient(vClients, Client, AccountNumber);
            return;
        }
    }

    cout << "Client with account number (" << AccountNumber << " ) NOT found!\n";
}

int main()
{
    UpdateClientIfExists();

    return 0;
}