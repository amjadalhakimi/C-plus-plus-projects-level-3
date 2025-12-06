#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText()
{
    string text = "";
    cout << "please enter your string: ";
    getline(cin, text);

    return text;
}


string JoinString(vector<string> vWords, string delim)
{
    string text = "";

    for (string &word : vWords)
    {
        text += word + delim;
    }

    return text.substr(0, text.length() - delim.length());
}

string JoinString(string Words[], short length, string delim)
{
    string text = "";

    for (short i = 0; i < length; i++)
    {
        text += Words[i] + delim;
    }

    return text.substr(0, text.length() - delim.length());
}

void PrintResult()
{
    vector<string> vWords = {"My", "name", "is", "Amjad"};
    string Words[] = {"My", "name", "is", "Amjad"};

    cout << "Vector after joing: \n";
    cout << JoinString(vWords, ",,,") << endl;

    cout << "\nArray after joing: \n";
    cout << JoinString(Words, 4, ",,,") << endl;
}

int main()
{
    PrintResult();

    return 0;
}