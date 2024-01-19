#include <iostream>
using namespace std;

long long int arr[500001];
long long int parr[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n;
	cin >> n;
	for (int i = 2; i < 500001; i++) arr[i] = i;
	for (int i = 2; i * i < 500001; i++) {
		if (!arr[i]) continue;
		for (int j = i * i; j < 500001; j += i) {
			arr[j] = 0;
		}
	}
	int s = 0;
	for (int i = 1; i < 500001; i++) {
		if (arr[i]) parr[s++] = arr[i] * arr[i];
	}
	long long int reCnt = 0;
	long long int pretotalReCnt = 0;
	long long int curN = n;
	while (1) {
		reCnt = 0;
		for (int i1 = 0; parr[i1] <= curN; i1++) {
			reCnt += curN / parr[i1];
			for (int i2 = 0; parr[i1] * parr[i2] <= curN && i2 < i1; i2++) {
				reCnt -= curN / (parr[i1] * parr[i2]);
				for (int i3 = 0; parr[i1] * parr[i2] * parr[i3] <= curN && i3 < i2; i3++) {
					reCnt += curN / (parr[i1] * parr[i2] * parr[i3]);
					for (int i4 = 0; parr[i1] * parr[i2] * parr[i3] * parr[i4] <= curN && i4 < i3; i4++) {
						reCnt -= curN / (parr[i1] * parr[i2] * parr[i3] * parr[i4]);
						for (int i5 = 0; parr[i1] * parr[i2] * parr[i3] * parr[i4] * parr[i5] <= curN && i5 < i4; i5++) {
							reCnt += curN / (parr[i1] * parr[i2] * parr[i3] * parr[i4] * parr[i5]);
							for (int i6 = 0; parr[i1] * parr[i2] * parr[i3] * parr[i4] * parr[i5] * parr[i6] <= curN && i6 < i5; i6++) {
								reCnt -= curN / (parr[i1] * parr[i2] * parr[i3] * parr[i4] * parr[i5] * parr[i6]);
							}
						}
					}
				}
			}
		}
		reCnt = curN - reCnt;
		if (pretotalReCnt == reCnt) {
			cout << curN;
			break;
		}
		curN += (reCnt - pretotalReCnt);
		pretotalReCnt = reCnt;
	}
}