#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A[10], B[10]; // A와 B의 카드 배열
    for (int i = 0; i < 10; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> B[i];
    }

    int aWins = 0, bWins = 0; // A와 B의 승리 횟수

    // 각 라운드에서 카드 비교
    for (int i = 0; i < 10; i++) {
        if (A[i] > B[i]) {
            aWins++;
        } else if (A[i] < B[i]) {
            bWins++;
        }
    }

    // 결과 출력
    if (aWins > bWins) {
        cout << "A";
    } else if (aWins < bWins) {
        cout << "B";
    } else {
        cout << "D"; // 비긴 경우
    }
}