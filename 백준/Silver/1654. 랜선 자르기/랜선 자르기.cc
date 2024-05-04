#include <iostream>
#include <cstdlib>
using namespace std;

int lanCable[10000];

// 분화되는 막대 수를 구한다.
int getCount(int K, int searchPoint) {
    int count = 0;
    for (int i = 0; i < K; i++)
    {
        count += lanCable[i] / searchPoint;
    }
    return count;
}

// 중간 값을 구한다.
int getSearchPoint(int searchStart, int searchEnd) {
    return searchStart + (searchEnd - searchStart) / 2;
}

// count 값이 N보다 크다면 1(searchPoint가 N보다 작다는 뜻) 작으면 -1(searchPoint가 N보다 크다는 뜻) 같다면 0을 리턴
int getResult(int count, int N) {
    if (N < count) {
        return 1;
    }
    else if (N > count) {
        return -1;
    }
    if (N == count) {
        return 0;
    }
}

int algorithm(int searchPoint, int searchStart, int searchEnd, int K, int N, int maxLength) {
    int count;

    while (true)
    {
        // 중간 값을 가져온다.
        searchPoint = getSearchPoint(searchStart, searchEnd);

        // 중간 값의 막대 수를 구한다.
        count = getCount(K, searchPoint);

        // 카운트 값을 비교하여 계산한다.
        switch (getResult(count, N)) {
        case 1:
            // 상단부 탐색을 위해 최소 범위를 중간값으로 이동
            if (searchStart < searchEnd) {
                // 상단부로 이동해서 계산해야 되는데 조건식이 말단인 경우(다음 루프에서 반복적으로 한칸 내려옴)
                if (searchEnd - searchPoint == 1) {
                    // N개 이상으로 나눌 수 있을 때 최대 값인 경우
                    if (getCount(K, searchEnd) != N && getCount(K, searchEnd) != N) {
                        cout << searchPoint << "\n";
                        exit(0);
                    }
                    cout << searchEnd << "\n";
                    exit(0);
                }
                searchStart = searchPoint;
            }
            else {
                // 상단부로 이동해서 계산해야 되는데 조건식이 말단인 경우(다음 루프에서 반복적으로 한칸 내려옴)
                if (searchStart - searchPoint == 1) {
                    // N개 이상으로 나눌 수 있을 때 최대 값인 경우
                    if (getCount(K, searchStart) != N && getCount(K, searchEnd) != N) {
                        cout << searchPoint << "\n";
                        exit(0);
                    }
                    cout << searchStart << "\n";
                    exit(0);
                }
                searchEnd = searchPoint;
            }
            break;
        case -1:
            // 하단부 탐색을 위해 최대 범위를 중간값으로 이동
            if (searchStart < searchEnd) {
                // 하단로 이동해서 계산해야 되는데 조건식이 말단인 경우(다음 루프에서 반복적으로 한칸 올라감)
                if (searchPoint - searchStart == 1) {
                    cout << searchStart << "\n";
                    exit(0);
                }
                searchEnd = searchPoint;
            }
            else {
                // 하단로 이동해서 계산해야 되는데 조건식이 말단인 경우(다음 루프에서 반복적으로 한칸 올라감)
                if (searchPoint - searchEnd == 1) {
                    cout << searchEnd << "\n";
                    exit(0);
                }
                searchStart = searchPoint;
            }
            break;
        case 0:
            // 포인트 값이 원하는 값과 일치하는 경우 (자신은 참인데 그 상단이 N이 아닌 것은 가장 큰 N으로 나눠지는 값이라는 것)
            if (getCount(K, searchPoint + 1) != N) {
                cout << searchPoint << "\n";
                exit(0);
            }
            // 포인트 값이 원하는 값과 일치하는데, 최대값이 아니라 반복이 필요 한 경우(searchPoint~최대값) 재탐색
            else {
                // 다음 값으로 이동해야하는데, 한칸만 이동해서 searchStart와 searchEnd의 차가 1이 되는 경우(다음 루프에서 반복적으로 한칸 내려옴)
                if (searchEnd - searchPoint == 1 && getCount(K, searchPoint + 1) == N) {
                    cout << searchEnd << "\n";
                    exit(0);
                }
                if (searchStart - searchPoint == 1 && getCount(K, searchPoint + 1) == N) {
                    cout << searchStart << "\n";
                    exit(0);
                }
                searchStart = searchPoint;
                searchEnd = maxLength;
                algorithm(searchPoint, searchStart, searchEnd, K, N, maxLength);
                continue;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    int maxLength = 0;
    for (int i = 0; i < K; i++) {
        cin >> lanCable[i];
        if (lanCable[i] > maxLength) maxLength = lanCable[i];
    }

    int searchEnd = maxLength;
    int searchStart = 1;
    int searchPoint = 0;

    algorithm(searchPoint, searchStart, searchEnd, K, N, maxLength);
}