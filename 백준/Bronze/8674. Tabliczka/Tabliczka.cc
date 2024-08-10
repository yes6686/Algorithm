#include <iostream>
using namespace std;
int main(){
    long long int a,b;
    cin >> a >> b;
    if(!(a % 2) || !(b % 2)) cout << 0;
    else cout << min(a, b);
}