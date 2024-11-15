#include <iostream>
#include <string.h>
using namespace std;

string str[3628801];
int visited[11];
string st;

int cnt = 1;

void dfs(int d,int n, string s) {
	if (d > n) {
		str[cnt] = s;
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(d + 1, n, s + st[i]);
			visited[i] = 0;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> st >> n) {
		cnt = 1;
		dfs(1, st.size(), "");
		cout << st << ' ' << n << " = ";
		if (cnt <= n) {
			cout << "No permutation" << '\n';
		}
		else {
			cout << str[n] << '\n';
		}
		memset(visited, 0, sizeof(visited));
	}	
}