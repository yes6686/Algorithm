#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int fishCnt[101];
int fishBowl[101][101];
int n, k;

queue<int>q[101];

void stackUp1() {
	int h = 1; // 쌓여있는 블록 길이       1 1 2 2 3 3 4 4
	int r = n; // 높이가 1인 블록 갯수     
	int ss = 0; // 쌓여있는 블록 갯수	   0 1 2 4 6 9
	int hh = 1; // 1 2 2 3 3 4 4
	int t = 1; 

	while (1) {
		if (hh > r) break;
		int cnt = 0;
		for (int i = ss; i < ss + h; i++) {
			for (int j = 0; j < n; j++) {
				if (fishBowl[i][j] == 0) break;
				q[i].push(fishBowl[i][j]);
				cnt++;
				fishBowl[i][j] = 0;
			}
		}

		if (h == 1 && cnt==2) {
			int k1 = q[ss].front();
			q[ss].pop(); 
			int k2 = q[ss].front();
			q[ss].pop();
			fishBowl[2][1] = k1;
			fishBowl[3][1] = k2;
		}
		else {
			int f = 0;
			while (!q[ss].empty()) {
				int kk = 1;
				for (int i = ss + h - 1; i >= ss; i--) {
					int k = q[i].front();
					q[i].pop();
					fishBowl[ss + h + f][kk] = k;
					kk++;
				} 
				f++;
			}
		}
		if (t % 2 == 0) {
			h++;
		}
		else {
			hh++;
		}
		t++;
		r = n - (h * hh);
		ss = n - r - h;
	}
}

int diff[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0,1,-1 };

void fishCntDiff() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (fishBowl[i][j]>0) {
				int kx = i;
				int ky = j;
				for (int t = 0; t < 4; t++) {
					int nx = kx + dx[t];
					int ny = ky + dy[t];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (fishBowl[nx][ny] == 0) continue;
					int diffV = abs(fishBowl[nx][ny] - fishBowl[kx][ky]);
					int d = diffV / 5;
					if (d == 0) continue;
					if (fishBowl[kx][ky] > fishBowl[nx][ny]) {
						diff[kx][ky] -= d;
						diff[nx][ny] += d;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fishBowl[i][j] += diff[i][j];
		}
	}
	memset(diff, 0, sizeof(diff));
}

void stackUp2() {

	for (int i = 0; i < n; i++) {
		fishBowl[i][0] = fishCnt[i];
	}
	stack<int>st[101];
	int ii = n;
	int s = 0;
	for (int T = 0; T < 2;T++) {
		ii /= 2;
		for (int i = s; i < s+ii; i++) {
			for (int j = 0; j < n; j++) {
				if (fishBowl[i][j] == 0) break;
				st[i].push(fishBowl[i][j]);
				fishBowl[i][j] = 0;
			}
		}

		if (T == 0) {
			int f = 0;
			for (int i = s+ii-1; i >=s; i--) {
				fishBowl[s+ii+f][1] = st[i].top();
				st[i].pop();
				f++;
			}
		}
		else {
			int ff = 0;
			for (int i = s+ii-1; i >=s; i--) {
				int f = 2;
				while (!st[i].empty()) {
					fishBowl[s + ii + ff][f] = st[i].top();
					st[i].pop();
					f++;
				}
				ff++;
			}
		}
		s += ii;
	}
}

void inarow() {
	int ii = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (fishBowl[i][j] == 0) break;
			fishCnt[ii++] = fishBowl[i][j];
		}
	}
	memset(fishBowl, 0, sizeof(fishBowl));
}

int minFishCnt = 10001;

void fishOneAdd() {
	minFishCnt = 10001;
	for (int i = 0; i < n; i++) {
		fishBowl[i][0] = fishCnt[i];
		minFishCnt = min(minFishCnt, fishCnt[i]);
	}
	for (int i = 0; i < n; i++) {
		if (fishCnt[i] == minFishCnt) {
			fishBowl[i][0] += 1;
		}
	}
}

int fishMaxMinDiff() {
	int maxCnt = 0;
	int minCnt = 10001;
	for (int i = 0; i < n; i++) {
		maxCnt = max(maxCnt, fishCnt[i]);
		minCnt = min(minCnt, fishCnt[i]);
	}
	return maxCnt - minCnt;
}

void solve() {

	// 1. 물고기의 수가 최소인 어항 모두에 한 마리씩 넣는다
	fishOneAdd();
	// 2. 공중 부양 작업
	stackUp1();

	//3. 어항에 있는 물고기의 수를 조절
	fishCntDiff();

	//4. 다시 어항을 바닥에 일렬로 놓기
	inarow();

	//5. 다시 공중 부양 작업
	stackUp2();

	//6. 다시 어항에 있는 물고기의 수를 조절
	fishCntDiff();

	//7. 다시 다시 어항을 바닥에 일렬로 놓기
	inarow();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> fishCnt[i];
	}
	int ans = 0;
	while (1) {
		if (fishMaxMinDiff() <= k) {
			cout << ans << '\n';
			break;
		}
		solve();
		ans++;
	}
}