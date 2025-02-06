
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // 센서 입력
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 센서가 k개 이상이면 모든 센서에 기지국을 두어야 하므로 거리합은 0
    if (n <= k) {
        cout << 0 << '\n';
        return 0;
    }

    // 센서 위치 정렬
    sort(arr, arr + n);

    // 센서 간 거리 차이 계산
    vector<int> gaps;
    for (int i = 0; i < n - 1; i++) {
        gaps.push_back(arr[i + 1] - arr[i]);
    }

    // 거리 차이 내림차순 정렬
    sort(gaps.rbegin(), gaps.rend());

    // 가장 긴 k-1개의 구간을 없애고 나머지 합산
    int ans = 0;
    for (int i = k - 1; i < gaps.size(); i++) {
        ans += gaps[i];
    }

    cout << ans << '\n';
    return 0;
}