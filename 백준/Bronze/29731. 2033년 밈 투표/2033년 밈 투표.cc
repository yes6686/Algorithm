#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string check[7] = { "Never gonna give you up",
                       "Never gonna let you down",
                       "Never gonna run around and desert you",
                       "Never gonna make you cry",
                       "Never gonna say goodbye",
                       "Never gonna tell a lie and hurt you",
                       "Never gonna stop" };
    int T, i;
    string s;
    cin >> T; 
    cin.ignore();
    while (T--){
        getline(cin, s);
        for (i = 0; i < 7; i++)
            if (s == check[i])
                break;
        if (i == 7){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}