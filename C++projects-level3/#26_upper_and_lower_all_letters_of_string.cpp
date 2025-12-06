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

string UpperAllLetterOfString(string text)
{
    
    for (short i = 0; i < text.length(); i++)
    {
            text[i] = toupper(text[i]);
    }

    return text;
}

string LowerAllLetterOfString(string text)
{
    
    for (short i = 0; i < text.length(); i++)
    {
            text[i] = tolower(text[i]);
    }

    return text;
}


void PrintResult()
{
    string OriginalText = ReadText();
    string UpperText = UpperAllLetterOfString(OriginalText);
    string LowerText = LowerAllLetterOfString(OriginalText);

    cout<<"\nString after upper:\n";
    cout << UpperText << endl;

    cout<<"\nString after lower:\n";
    cout << LowerText << endl;
}

int main()
{
    PrintResult();
    return 0;
}