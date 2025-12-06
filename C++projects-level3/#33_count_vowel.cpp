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

bool isVowel(char ch)
{
    ch = tolower(ch);
    return ((ch == 'a') || (ch == 'e') || (ch == 'o') || (ch == 'u') || (ch == 'i'));
}

short CountVowelLetters(string text)
{
    short counter = 0;
        
    for (short i = 0; i < text.length(); i++)
    {
        if (isVowel(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

void PrintResult()
{
    string OriginalText = ReadText();
    cout << "Number of vowels is: " << CountVowelLetters(OriginalText) << endl;
}

int main()
{
    PrintResult();
    return 0;
}