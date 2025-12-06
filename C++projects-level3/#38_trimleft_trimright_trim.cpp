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

string TrimLeftString(string text)
{
    while (text[0] == ' ')
    {
        text.erase(0, 1);
    }

    return text;
}

string TrimRightString(string text)
{

    while (text[text.length() -1] == ' ')
    {
        text.erase(text.length() -1, text.length() - 1);
    }

    return text;
}

string TrimString(string text)
{
    return TrimRightString(TrimLeftString(text));
}

void PrintResult()
{
    string TextWithoutSpaces = TrimString(ReadText());
    cout<<TextWithoutSpaces<<endl;
}

int main()
{
    PrintResult();

    return 0;
}