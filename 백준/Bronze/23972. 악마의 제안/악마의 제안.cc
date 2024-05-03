#include <iostream>
using namespace std;

int main() {
    int k, n;
    long long int x;
    cin >> k >> n;
   long long int i = 1;
    while (true) {
        if (n == 1) {
            x = -1;
            break;
        }
        else if ((i-k)*n>=i) {
            x = i;
            break;
        }
        else {
            
        }
        i++;
    }
    cout << x << endl;

}