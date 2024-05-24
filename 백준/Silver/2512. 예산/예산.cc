#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int N, M;

int bSearch(int end)
{
        int start = 0;
        int sum = 0;
        int cost = 0;
        while (start <= end) {
                sum = 0;
                cost = (start + end) / 2;

                for (int i = 0; i < N; i++) {
                        if (arr[i] < cost)
                                sum += arr[i];
                        else
                                sum += cost;
                }

                if (sum <= M) {
                        start = cost + 1;
                }
                else {
                        end = cost - 1;
                }
        }

        return end;
}

int main(void)
{
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
                scanf("%d", &arr[i]);
        scanf("%d", &M);

        sort(arr, arr + N);
        printf("%d", bSearch(arr[N - 1]));
        return 0;
}