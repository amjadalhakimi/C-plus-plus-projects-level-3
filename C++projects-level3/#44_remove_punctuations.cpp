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

string RemovePunctuations(string OriginalText)
{
    string FinalText = "";
    for (short i = 0; i < OriginalText.length(); i++)
    {
        if (!ispunct(OriginalText[i]))
        {
            FinalText += OriginalText[i];
        }
        
    }
    return FinalText;
}

void PrintResult()
{
    string OriginalText = ReadText();
    cout<<RemovePunctuations(OriginalText)<<endl;
}


int main()
{
    PrintResult();
    return 0;
}