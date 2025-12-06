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

vector <string> SplitString(string text, string delim)
{
    vector <string> vWords;

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

void PrintResult()
{
    vector <string> vWords = SplitString(ReadText(), " ");
    cout << "Tokens = "<< vWords.size()<<endl;

    for(string &word : vWords)
    {
        cout<<word<<endl;
    }
}

int main()
{
    PrintResult();
    cout << endl;
    return 0;
}