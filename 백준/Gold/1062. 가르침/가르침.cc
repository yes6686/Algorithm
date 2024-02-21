#include <iostream>
using namespace std;

int barr[51];

int n, k;
int visited[27];
int maxAns = 0;

void bfs(int x, int d,int bi) {

	if (d >=k) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((barr[i] & bi) == barr[i]) {
				cnt++;
			}
		}
		maxAns = max(maxAns, cnt);
		return;
	}

	for (int i = x; i <= 26; i++) {
		
		if (visited[i] == 0) {
			visited[i] = 1;
			bfs(i,d + 1, (bi | (1<<(i-1))));
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			barr[i] = (barr[i] | (1 << s[j] - 'a'));
		}
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	char a = 'a'; char N = 'n'; char t = 't';	char i = 'i';	char c = 'c';
	visited[a - 'a' + 1] = 1;
	visited[N - 'a' + 1] = 1;
	visited[t - 'a' + 1] = 1;
	visited[i - 'a' + 1] = 1;
	visited[c - 'a' + 1] = 1;
	int cc = 0;
	cc = (cc | 1 << (a - 'a'));
	cc = (cc | 1 << (N - 'a'));
	cc = (cc | 1 << (t - 'a'));
	cc = (cc | 1 << (i - 'a'));
	cc = (cc | 1 << (c - 'a'));
	bfs(1,5, cc);
	cout << maxAns;
}