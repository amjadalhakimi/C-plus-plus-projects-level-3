#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

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

void PrintHeader(short size)
{
    cout << "\t\t\tClinet List (" << size << ") Clinet(s)\n";
    cout << "--------------------------------------------------------------------------------\n";

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "PinCode";
    cout << "| " << left << setw(25) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance"<<endl;
    cout << "--------------------------------------------------------------------------------\n";
}

void PrintClientData(sClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(25)<< Client.Name;
    cout << "| " << left << setw(12) << Client.Phone; 
    cout << "| " << left << setw(12) << Client.AccountBalance << endl;
}

void PrintClients()
{
    vector<string> vClients;
    sClient ClientData;
    LoadDataFromFileToVector(ClientsFileName, vClients);
    PrintHeader(vClients.size());
    
    for (string &Client : vClients)
    {
        ClientData = SplitStringToStract(Client);
        PrintClientData(ClientData);
    }

    cout << "--------------------------------------------------------------------------------\n";
}

int main()
{
    PrintClients();

    return 0;
}