#include <iostream>
#include <string>
using namespace std;

int visited[9];

void dfs(int x,int d,string s) {
	if (d > x) {
		for (int i = 0; i < s.size(); i++) {
			cout << s[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= x; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(x, d+1,s+to_string(i));
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dfs(n,1,"");

}