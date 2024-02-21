#include <iostream>
using namespace std;

string s[51];
int alpa[27]; // a~z 1~26
int ch[27];

int N,K;
int maxAns = 0;

void bfs(int x,int d) {

	if (d >= K) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int check = 1;
			for (int j = 4; j < s[i].size()-4; j++) {
				if (alpa[s[i][j] - 'a' + 1] == 0) {
					check = 0;
					break;
				}
			}
			if (check == 1) {
				cnt++;
			}
		}
		maxAns = max(maxAns, cnt);
		return;
	}

	for (int i = x; i <= 26; i++) {
		if (alpa[i] == 0 ) {
			alpa[i] = 1;
			bfs(i, d + 1);
			alpa[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			ch[s[i][j] - 'a' + 1] = 1;
		}
	}
    if(K<5){
        cout<<0;
        return 0;
    }
	char a = 'a'; char n = 'n'; char t = 't';	char i = 'i';	char c = 'c';
	alpa[a - 'a' + 1] = 1;
	alpa[n - 'a' + 1] = 1;
	alpa[t - 'a' + 1] = 1;
	alpa[i - 'a' + 1] = 1;
	alpa[c - 'a' + 1] = 1;
	bfs(1, 5);
	cout << maxAns;

}