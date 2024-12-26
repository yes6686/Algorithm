
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[6];
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    int t, p;
    cin >> t >> p;

    // 최소 작업 수 계산
    int minTasks = 0;
    for (int i = 0; i < 6; i++) {
        minTasks += (arr[i] + t - 1) / t; // 올림하여 작업 수 계산
    }

    // n을 p로 나눈 몫과 나머지 계산
    int maxGroups = n / p;
    int remainingItems = n % p;

    // 결과 출력
    cout << minTasks << '\n';
    cout << maxGroups << ' ' << remainingItems << '\n';

    return 0;
}
