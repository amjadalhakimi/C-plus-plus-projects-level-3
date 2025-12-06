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

char InvertCharacterCase(char letter)
{
    return (isupper(letter)) ? tolower(letter) : toupper(letter);
}

short LetterFrequencyInString(string text, char letter, bool MatchCase = true)
{
    short counter = 0;
    for (short i = 0; i < text.length(); i++)
    {
        if (MatchCase)
        {
            if (text[i] == letter)
                counter++;
        }
        else
        {
            if (tolower(text[i]) == tolower(letter))
                counter++;
        }
    }

    return counter;
}

void PrintResult()
{
    string OriginalText = ReadText();
    char letter = ReadCharacter();
    cout << "Letter '" << letter << "' Count = "
         << LetterFrequencyInString(OriginalText, letter) << endl;
    cout << "Letter '" << letter << "' or '"
         << InvertCharacterCase(letter) << "' Count = "
         << LetterFrequencyInString(OriginalText, letter, false) << endl;
}

int main()
{
    PrintResult();
    return 0;
}