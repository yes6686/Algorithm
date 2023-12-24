#include <iostream>	
#include <algorithm>
#include <cmath>
using namespace std;

int parent[10001];

int GetParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent[x]);
}

void unionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int findParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a == b) return 1;
	else return 0;
}

struct st {
	double sx;
	double sy;
};

struct edge {
	double x;
	double y;
	double distance;
};

bool compare(edge a, edge b) {
	return a.distance < b.distance;
}


edge Ed[10001];
st S[101];

int main() {


	int n;
	cin >> n;
	double a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		S[i].sx = a;
		S[i].sy = b;
	}
	for (int i = 1; i <= n*n; i++) {
		parent[i] = i;
	}

	int s = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				Ed[s].x = i;
				Ed[s].y = j;
				Ed[s].distance = sqrt((S[i].sx - S[j].sx) * (S[i].sx - S[j].sx) +
					(S[i].sy - S[j].sy) * (S[i].sy - S[j].sy));
				s++;
			}
		}
	}
	sort(Ed, Ed + s,compare);
	double sum = 0;
	for (int i = 0; i < s; i++) {
		if (!findParent(Ed[i].x, Ed[i].y)) {
			unionParent(Ed[i].x, Ed[i].y);
			sum += Ed[i].distance;
		}

	}
	cout << sum;


}