#include <iostream>
using namespace std;
int N, answer;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> str;
        if (str[0] == 'C')
        {
            ++answer;
        }
    }
    cout << answer;
}