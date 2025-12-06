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

char InvertCharacterCase(char letter)
{
    return (isupper(letter)) ? tolower(letter) : toupper(letter);
}

string InvertAllLettersCase(string text)
{
    for (short i = 0; i < text.length(); i++)
    {
        text[i] = InvertCharacterCase(text[i]);
    }

    return text;
}

void PrintResult()
{
    string InvertedText = InvertAllLettersCase(ReadText());

    cout << "\nString after inverting:\n";
    cout << InvertedText << endl;

}

int main()
{
    PrintResult();
    return 0;
}