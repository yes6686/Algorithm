#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 인덱스, 비용
vector<pair <int, int>> p;
int counter[1001];

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    //값입력
    int tempValue;
    for (int i = 0; i < N; i++)
    {
        cin >> tempValue;
        p.push_back(pair<int, int>(i, tempValue));
    }

    // 정렬
    sort(p.begin(), p.end(), [](pair<int, int>& left, pair<int, int>& right) {
        return left.second < right.second;
        });

    int inputM;
    int maxIndex = 0;
    for (int i = 0; i < M; i++)
    {
        // 최대 sceond 계산
        cin >> inputM;
        for (int j = N - 1; j >= 0; j--)
        {
            if (inputM >= p[j].second) {
                maxIndex = j;
                break;
            }
        }

        // 최소 first 계산
        for (int j = N - 1; j >= 0; j--)
        {
           // if (p[j].second != p[maxIndex].second) break;
            if (p[maxIndex].first > p[j].first && p[j].second<=inputM)
            {
                maxIndex = j;
            }
        }
        counter[p[maxIndex].first]++;
    }

    // 최대 카운터 계산
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (counter[result] < counter[i]) {
            result = i;
        }
    }
    cout << ++result << "\n";
}