
#include <iostream>
#include <map>
#include <cmath>
#define INF 1000000000
using namespace std;

int cnt4[100001];
map<int, int> mp3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s = 1;

    // 삼각수를 미리 계산하여 map에 저장
    while (true) {
        long long int ss = (s * (s + 1)) / 2;
        if (ss > INF) {
            break;
        }
        mp3[ss] = 1;
        s++;
    }

    // 제곱수 중 하나 적은 값이 삼각수인 것을 카운트
    s = 1;
    while (true) {
        long long int ss = s * s;
        if (ss > INF) {
            break;
        }
        if (mp3[ss - 1] == 1) {
            cnt4[s] = cnt4[s - 1] + 1;
        } else {
            cnt4[s] = cnt4[s - 1];
        }
        s++;
    }

    // 각 입력 범위에 대한 결과 계산 및 출력
    int t = 1;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        
        int cnt = cnt4[(int)sqrt(b - 1)] - cnt4[(int)sqrt(a)];
        cout << "Case " << t++ << ": " << cnt << '\n';
    }
    return 0;
}
