#include <iostream>

using namespace std;

string ReadText()
{
    string text = "";
    cout<<"please enter you string: ";
    getline(cin, text);

    return text;
}

void PrintFirstLetterOfEachWord(string text)
{
    bool isFirstLetter = true;
    for(short i = 0; i < text.length(); i++){
        if (text[i] != ' ' && isFirstLetter)
        {
            cout<<text[i]<<endl;
        }

        isFirstLetter = (text[i] == ' ')? true : false;
    }
}

int main()
{
    PrintFirstLetterOfEachWord(ReadText());
    return 0;
}