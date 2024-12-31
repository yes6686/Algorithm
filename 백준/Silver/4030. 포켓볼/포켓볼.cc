#include <iostream>
#include <map>
#include <cmath>
#define INF 1000000000
using namespace std;


int cnt4[100001];
int check3[100001];
map<long long int, int>mp4;
map<long long int, int>mp3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int s = 1;

    while (true) {
        long long int ss = (s * (s + 1)) / 2;
        if (ss > INF) {
            break;
        }
        mp3[ss] = 1;
        s++;
    }
    s = 1;
    while (true) {
        long long int ss = s * s;
        if (ss > INF) {
            break;
        }
        if (mp3[ss - 1] == 1) {
           // cout << "s : " << s << '\n';
            cnt4[s] = cnt4[s - 1] + 1;
        }
        else {
            cnt4[s] = cnt4[s - 1];
        }
        s++;
    }


    int t = 1;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        //cout << "a : "<<cnt4[(int)sqrt(a)] << '\n';
        //cout << "b : "<<cnt4[(int)sqrt(b)] << '\n';
        int cnt = cnt4[(int)sqrt(b-1)] - cnt4[(int)sqrt(a)];
        cout << "Case " << t++ << ": " << cnt << '\n';
    }


}
