#include <iostream>
using namespace std;
int main(){
    int n, ans = 1;
    cin >> n;
    for(int i = 1; i <= n; ans *= i, ans %= 10, i++);
    cout << ans;
}