#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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


sClient ReadNewClient()
{
    sClient Client;

    cout << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);
    cout << "Enter PinCode: ";
    getline(cin, Client.PinCode);
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


void AddClientToFile(string FileName, string ClientInfo)
{
    fstream myFile;
    myFile.open(FileName, ios::app);

    if (myFile.is_open())
    {
        myFile << ClientInfo << endl;
        myFile.close();
    }
}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddClientToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddClients()
{
    char Again = 'y';

    while (tolower(Again) == 'y')
    {
        system("clear");
        cout << "Adding new client:\n\n";
        AddNewClient();

        cout<<endl<<"Client Added successfully, Do you want to add more Clients (y,n): ";
        cin>>Again;

    }
}

int main()
{
    AddClients();

    return 0;
}