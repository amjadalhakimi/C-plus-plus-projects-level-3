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

short CountEachWordInString(string text)
{
    string sWord, delim = " ";
    short pos = 0, counter = 1;

    while (((pos = text.find(delim)) != std::string::npos))
    {
        sWord = text.substr(0, pos);
        if (sWord != "")
        {
            counter++;
        }

        text.erase(0, pos + delim.length());
    }

    return counter;
}

void PrintResult()
{
    string OriginalText = ReadText();
    cout << "Your words in string are: " << CountEachWordInString(OriginalText);
}

int main()
{
    PrintResult();
    cout << endl;
    return 0;
}