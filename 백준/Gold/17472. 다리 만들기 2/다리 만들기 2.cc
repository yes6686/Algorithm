#include <iostream>
#include <algorithm>
/*
// memset을 이용하여 arr[5] -1로 초기화
memset(arr, -1, sizeof(arr));

//memset으로 2차원 배열도 초기화 할 수 있다.
memset(arr2, 0, sizeof(arr2));*/


using namespace std;

int parent[7];

struct st {
	int x, y;
};

struct edge {
	int a, b;
	int dis;
};

edge Ed[60001];
st St[255];

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

int arr[12][12];
int s[12][12];
int n, m;
int kk = 0;
void di1(int x, int y,int startx,int starty,int cnt) {//상
	
	if (x < 1) return;

	if (arr[x - 1][y] == 1) {
		if (cnt >= 2) {
			Ed[kk].a = s[startx][starty];
			Ed[kk].b = s[x-1][y];
			Ed[kk].dis = cnt;
			kk++;
		}
		return;

	}
	if (arr[x - 1][y] == 0) {
		di1(x - 1, y,startx,starty, cnt + 1);
	}
	

}
void di2(int x, int y, int startx, int starty, int cnt) {//하
	if (x > n) return;

	if (arr[x + 1][y] == 1) {
		if (cnt >= 2) {
			Ed[kk].a = s[startx][starty];
			Ed[kk].b = s[x+1][y];
			Ed[kk].dis = cnt;
			kk++;
		}
		return;
	}
	if (arr[x + 1][y] == 0) {
		di2(x + 1, y, startx, starty, cnt + 1);
	}
}
void di3(int x, int y, int startx, int starty, int cnt) {//좌
	if (y <1) return;

	if (arr[x][y-1] == 1) {
		if (cnt >= 2) {
			Ed[kk].a = s[startx][starty];
			Ed[kk].b = s[x][y-1];
			Ed[kk].dis = cnt;
			kk++;	
		}
		return;
	}
	if (arr[x][y-1] == 0) {
		di3(x, y-1, startx, starty, cnt + 1);
	}
}
void di4(int x, int y, int startx, int starty, int cnt) {//우
	if (y > m) return;

	if (arr[x][y + 1] == 1) {
		if (cnt >= 2) {
			Ed[kk].a = s[startx][starty];
			Ed[kk].b = s[x][y+1];
			Ed[kk].dis = cnt;
			kk++;
		}
		return;
	}
	if (arr[x][y + 1] == 0) {
		di4(x, y + 1, startx, starty, cnt + 1);
	}
}

int ch[11][11];

void spread(int x, int y,int c) {
	if (ch[x][y]) return;
	ch[x][y] = 1;
	if (arr[x][y] == 0) {
		return;
	}

	if (arr[x][y] == 1) {
		s[x][y] = c;
	}
	spread(x + 1, y, c);
	spread(x - 1, y, c);
	spread(x, y + 1, c);
	spread(x, y - 1, c);

}


int main() {
	int ss = 1;
	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1 && s[i][j]==0) {

				spread(i, j, ss);
				ss++;
			}
			
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				di1(i, j,i,j, 0);
				di2(i, j,i,j, 0);
				di3(i, j,i,j, 0);
				di4(i, j,i,j, 0);	
			}

		}
	}
	sort(Ed, Ed + kk, compare);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < kk; i++) {
		if (!findParent(Ed[i].a, Ed[i].b)) {
			unionParent(Ed[i].a, Ed[i].b);
			sum += Ed[i].dis;
			cnt++;
		}
	}
	if (ss - 2 == cnt) {
		cout << sum << '\n';
	}
	else {
		cout << -1 << '\n';
	}

}