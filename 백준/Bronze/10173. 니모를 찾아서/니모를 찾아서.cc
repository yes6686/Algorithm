#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        string str;
        getline(cin, str);

        if (str == "EOI")
            break;
        for (int i = 0; i < str.size(); i++)
            str[i] = toupper(str[i]);
        if (str.find("NEMO") != string::npos)
            cout << "Found" << "\n";
        else
            cout << "Missing" << "\n";
    }
}
