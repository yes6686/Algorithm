#include <iostream>
using namespace std;
int main(){
    double k, ans;
    cin >> k;
    ans = 25.0 + k * 0.01;
    if(ans <= 100) printf("100.00");
    else if(ans >= 2000) printf("2000.00");
    else printf("%.2f", ans);
}