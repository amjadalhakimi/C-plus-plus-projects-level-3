#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string text = "";
    cout << "please enter you string: ";
    getline(cin, text);

    return text;
}

string UpperFirstLetterOfEachWord(string text)
{
    bool isFirstLetter = true;
    for (short i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ' && isFirstLetter)
        {
            text[i] = toupper(text[i]);
        }

        isFirstLetter = (text[i] == ' ') ? true : false;
    }

    return text;
}

void PrintResult()
{
    string UpperText = UpperFirstLetterOfEachWord(ReadText());
    cout << UpperText << endl;
}

int main()
{
    PrintResult();
    return 0;
}