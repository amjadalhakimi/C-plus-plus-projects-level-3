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

bool isVowel(char ch)
{
    ch = tolower(ch);
    return ((ch == 'a') || (ch == 'e') || (ch == 'o') || (ch == 'u') || (ch == 'i'));
}

void PrintResult()
{
    char letter = ReadCharacter();
    if (isVowel(letter))
        cout << "Yes, letter '" << letter << "' is vowel" << endl;
    else
        cout << "No, letter '" << letter << "' is NOT vowel" << endl;
}

int main()
{
    PrintResult();
    return 0;
}