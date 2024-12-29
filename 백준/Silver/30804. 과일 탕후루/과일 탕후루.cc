#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int arr[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n <= 2) {
        cout << n << '\n';
        return 0;
    }

    int start = 0, end = 0, maxCount = 2;
    unordered_map<int, int> fruitCount;

    while (end < n) {
        fruitCount[arr[end]]++;

        while (fruitCount.size() > 2) {
            fruitCount[arr[start]]--;
            if (fruitCount[arr[start]] == 0) {
                fruitCount.erase(arr[start]);
            }
            start++;
        }

        maxCount = max(maxCount, end - start + 1);
        end++;
    }

    cout << maxCount << '\n';
}
