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

char ReadCharacter()
{
    char letter = ' ';
    cout << "please enter your letter: ";
    cin >> letter;

    return letter;
}

short LetterFrequencyInString(string text, char letter)
{
    short counter = 0;
    for (short i = 0; i < text.length(); i++)
    {
        if (text[i] == letter)
            counter++;
    }

    return counter;
}

void PrintResult()
{
    string OriginalText = ReadText();
    char letter = ReadCharacter();
    cout << "Letter '" << letter << "' Count = " << LetterFrequencyInString(OriginalText, letter) << endl;
}

int main()
{
    PrintResult();
    return 0;
}