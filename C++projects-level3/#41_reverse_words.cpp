#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText()
{
    string text = "";
    cout << "please enter your string: ";
    getline(cin, text);

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

string ReverseWordsInString(string OriginalText)
{
    string ReversedText = "", delim = " ";

    vector<string> vWords = SplitString(OriginalText, delim);


    for (short i = vWords.size() - 1; i >= 0; i--)
    {
        ReversedText += vWords[i] + delim;
    }

    return ReversedText.substr(0, ReversedText.length() - delim.length());
}

void PrintResult()
{
    cout << ReverseWordsInString(ReadText()) << endl;
}

int main()
{
    PrintResult();

    return 0;
}