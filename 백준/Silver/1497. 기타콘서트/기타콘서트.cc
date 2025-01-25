#include <iostream>
using namespace std;

string s[11];
long long int arr[51];

int n, m;

int maxGitCnt = -1;
int maxPlayCnt = 0;

void go(int d,long long int s,int gCnt,int pCnt) {

	if (d >= n){
		if (maxPlayCnt < pCnt) {
			maxPlayCnt = pCnt;
			maxGitCnt = gCnt;
		}
		else if (maxPlayCnt == pCnt) {
			if (maxGitCnt > gCnt) {
				maxGitCnt = gCnt;
			}
		}

		return;
	}

	long long int fs = s;	
	fs |= arr[d];
	int playCnt = 0; 
	for (int i = 0; i < m; i++) {
		if ((fs & (1L<<i))) {
			playCnt++;
		}
	}
	
	go(d + 1, fs, gCnt+1,playCnt);
	go(d + 1, s, gCnt,pCnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> s[i] >> a;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == 'Y') {
				arr[i] |= (1L << j);
			}
		}
	}
	go(0, 0,0,0);

	cout << maxGitCnt << '\n';

}