#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);

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

vector<string> SplitString(string text, string delim)
{
    vector<string> vWords;

    string sWord;

    short pos = 0;

    while (((pos = text.find(delim)) != std::string::npos))
    {
        sWord = text.substr(0, pos);
        if (sWord != "")
        {
            vWords.push_back(sWord);
        }

        text.erase(0, pos + delim.length());
    }

    if (text != "")
    {
        vWords.push_back(text);
    }

    return vWords;
}

string ReplaceWordsInString(string OriginalText, string OldWord, string NewWord, bool MatchCase = true)
{
    string ReplacedText = "", delim = " ";

    vector<string> vWords = SplitString(OriginalText, delim);

    for (string &word : vWords)
    {
        if (MatchCase)
        {
            if (word == OldWord)
            {
                word = NewWord;
            }
        }
        else
        {
            if (LowerAllLetterOfString(word) == LowerAllLetterOfString(OldWord))
            {
                word = NewWord;
            }
        }

        ReplacedText += word + delim;
    }

    return ReplacedText.substr(0, ReplacedText.length() - delim.length());
}

void PrintResult()
{
    string OriginalText = ReadText("please enter your string: ");
    string OldWord = ReadText("the string to replace: ");
    string NewWord = ReadText("replace " + OldWord + " to: ");
    cout << "match case: " << ReplaceWordsInString(OriginalText, OldWord, NewWord) << endl;
    cout << "not match case: " << ReplaceWordsInString(OriginalText, OldWord, NewWord, false) << endl;

}

int main()
{
    PrintResult();

    return 0;
}