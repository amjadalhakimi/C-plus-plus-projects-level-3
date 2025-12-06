#include <iostream>
#include <string>

using namespace std;

enum enLetters
{
    Capital = 1,
    Small = 2,
    All = 3
};

string ReadText()
{
    string text = "";
    cout << "please enter your string: ";
    getline(cin, text);

    return text;
}

short CountLetters(string text, enLetters letters = enLetters::All)
{

    if (letters == enLetters::All)
    {
        return text.length();
    }

    short counter = 0;

    for (short i = 0; i < text.length(); i++)
    {
        if (letters == enLetters::Capital && isupper(text[i]))
        {
            counter++;
        }
        else if (letters == enLetters::Small && islower(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

// Two different functions without enums

short CountCapitalLetters(string text)
{
    short counter = 0;
    for (short i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

short CountSmallLetters(string text)
{
    short counter = 0;
    for (short i = 0; i < text.length(); i++)
    {
        if (islower(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

void PrintResult()
{
    string OriginalText = ReadText();

    cout << "\nString length = " << OriginalText.length() << endl;
    cout << "Capital letters count = " << CountCapitalLetters(OriginalText) << endl;
    cout << "Small letters count = " << CountSmallLetters(OriginalText) << endl;

    cout<<"\n##############################\n";
    cout<<"   This is another solution\n";
    cout<<"##############################\n\n";

    cout << "String length = " << CountLetters(OriginalText) << endl;
    cout << "Capital letters count = " << CountLetters(OriginalText, enLetters::Capital) << endl;
    cout << "Small letters count = " << CountLetters(OriginalText, enLetters::Small) << endl;
}

int main()
{
    PrintResult();
    return 0;
}