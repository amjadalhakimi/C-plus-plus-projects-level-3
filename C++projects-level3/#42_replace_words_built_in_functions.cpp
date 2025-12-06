#include <iostream>
#include <string>

using namespace std;

string ReadText(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);

    return text;
}

string ReplaceWordsInStringUsingBuildIn(string OriginalText, string OldWord, string NewWord)
{
    short pos = OriginalText.find(OldWord);

    while (pos != std::string::npos)
    {
        OriginalText = OriginalText.replace(pos, OldWord.length(), NewWord);
        pos = OriginalText.find(OldWord);
    }
    
    return OriginalText;
}

void PrintResult()
{
    string OriginalText = ReadText("please enter your string: ");
    string OldWord = ReadText("the string to replace: ");
    string NewWord = ReadText("replace " + OldWord + " to: ");
    cout << ReplaceWordsInStringUsingBuildIn(OriginalText, OldWord, NewWord) << endl;

}

int main()
{
    PrintResult();

    return 0;
}