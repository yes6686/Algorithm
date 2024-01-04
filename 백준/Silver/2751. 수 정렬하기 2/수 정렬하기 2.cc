#include <iostream>
#include <algorithm>
using namespace std;
int da[1000001];
void quickSort(int* data, int start, int end) { // 5 4 3 2 1 
	if (start >= end) {
		return;
	}
	int key = start;
	int i = start + 1;
	int j = end;
	int tmp;
	while (i <= j) {

		while (data[i] <= data[key]) {
			i++;
		}
		while (data[j] >= data[key]&& j>start) {
			j--;
		}
		if (i > j) {
			tmp = data[key];
			data[key] = data[j];
			data[j] = tmp;
		}
		else {
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j+1, end);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> da[i];
	}

	random_shuffle(da, da + n);
	quickSort(da,0,n-1);

	for (int i = 0; i < n; i++) {
		cout<< da[i]<<'\n';
	}
}