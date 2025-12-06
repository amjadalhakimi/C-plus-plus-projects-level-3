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


string JoinString(vector <string> vWords, string delim)
{
    string text = "";

    for(string &word : vWords)
    {
        text += word + delim; 
    }

    return text.substr(0,text.length() - delim.length());
}

void PrintResult()
{
    vector <string> vWords = {"My", "name", "is", "Amjad"};
    cout<<JoinString(vWords, ",,,")<<endl;
}

int main()
{
    PrintResult();
    
    return 0;
}