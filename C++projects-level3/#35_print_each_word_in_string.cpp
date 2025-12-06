#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string text = "";
    cout << "please enter your string: ";
    getline(cin, text);

    return text;
}

void PrintEachWordInString(string text)
{
    string sWord, delim = " ";
    short pos = 0;

    while (((pos = text.find(delim)) != std::string::npos))
    {
        sWord = text.substr(0, pos);
        if (sWord != "")
        {
            cout << sWord << endl;
        }

        text.erase(0, pos + delim.length());
    }

    if (text != "")
    {
        cout << text << endl;
    }
}

void PrintResult()
{
    string OriginalText = ReadText();
    cout << "Your words in string are: \n";
    PrintEachWordInString(OriginalText);
}

int main()
{
    PrintResult();
    cout << endl;
    return 0;
}