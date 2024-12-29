#include <iostream>
using namespace std;

const int MAX_SIZE = 10001;
int arr[MAX_SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arraySize, targetSum;
    cin >> arraySize >> targetSum;

    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0, currentSum = 0, count = 0;

    while (end <= arraySize) {
        if (currentSum < targetSum) {
            currentSum += arr[end++];
        }
        else if (currentSum > targetSum) {
            currentSum -= arr[start++];
        }
        else {
            count++;
            currentSum += arr[end++];
        }
    }

    cout << count << '\n';

    return 0;
}
