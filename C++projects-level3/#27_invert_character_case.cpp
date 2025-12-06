#include <iostream>
#include <string>

using namespace std;

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

void PrintResult()
{
    char letter = InvertCharacterCase(ReadCharacter());
    cout << "\nCharacter after inverting: " << letter << endl;
}

int main()
{
    PrintResult();
    return 0;
}