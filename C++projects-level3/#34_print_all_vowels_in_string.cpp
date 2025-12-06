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

void PrintVowelLettersInString(string text)
{
    for (short i = 0; i < text.length(); i++)
    {
        if (isVowel(text[i]))
        {
            cout<<text[i]<<", ";
        }
    }

}

void PrintResult()
{
    string OriginalText = ReadText();
    cout << "Vowels in string are: ";
    PrintVowelLettersInString(OriginalText);
}

int main()
{
    PrintResult();
    cout<<endl;
    return 0;
}