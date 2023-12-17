#include <iostream>
#include <cmath>
#include <algorithm>
/*
// memset을 이용하여 arr[5] -1로 초기화
memset(arr, -1, sizeof(arr));

//memset으로 2차원 배열도 초기화 할 수 있다.
memset(arr2, 0, sizeof(arr2));*/


using namespace std;

int parent[100001];

struct st {
	int x, y,z;
	int num;
};

struct edge {
	int a, b;
	int dis;
};

edge Ed[300001];
st St[100001];

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

bool compare(edge a, edge b) {
	return a.dis < b.dis;
}

bool compare2(st a, st b) {
	return a.x < b.x;
}
bool compare3(st a, st b) {
	return a.y < b.y;
}
bool compare4(st a, st b) {
	return a.z < b.z;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	for (int i = 1; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n; i ++) {
		cin >> St[i].x >> St[i].y >> St[i].z;
		St[i].num = i;
	}
	int kk = 0;
	sort(St, St + n, compare2);
	for (int i = 1; i < n; i++) {
		Ed[kk].a = St[i - 1].num;
		Ed[kk].b = St[i].num;	
		Ed[kk].dis= abs(St[i].x - St[i-1].x);
		kk++;
	}
	sort(St, St + n, compare3);
	for (int i = 1; i < n; i++) {
		Ed[kk].a = St[i - 1].num;
		Ed[kk].b = St[i].num;	
		Ed[kk].dis = abs(St[i].y - St[i - 1].y);
		kk++;
	}
	sort(St, St + n, compare4);
	for (int i = 1; i < n; i++) {
		Ed[kk].a = St[i - 1].num;
		Ed[kk].b = St[i].num;	
		Ed[kk].dis = abs(St[i].z - St[i - 1].z);
		kk++;
	}

	sort(Ed, Ed + kk, compare);
	long long int sum = 0;
	for (int i = 0; i < kk; i++) {
		if (!findParent(Ed[i].a, Ed[i].b)) {
			unionParent(Ed[i].a, Ed[i].b);
			sum += Ed[i].dis;
		}
	}
	cout << sum << '\n';

}