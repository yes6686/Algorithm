#include <iostream>
using namespace std;
int A, B, C, D, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> C >> D;
    answer = (A + B - 1) % 4;
    answer = (answer + C + D - 1) % 4;
    cout << answer + 1;
    return 0;
}