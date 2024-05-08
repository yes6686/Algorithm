#include <iostream>
#include <algorithm>
using namespace std;

char ad[3] = { 'A','B','C' };
char br[4] = { 'B','A','B','C'};
char go[6] = { 'C','C','A', 'A','B','B'};

bool compare(pair<int,string> a, pair<int,string> b) { 
	if (a.first == b.first) {
		return a < b;
	}
	return a > b; 
}

pair<int,string> ans[3];

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int adi = 0;
	int bri = 0;
	int goi = 0;
	ans[0].second = "Adrian";
	ans[1].second = "Bruno";
	ans[2].second = "Goran";
	for (int i = 0; i < n; i++) {
		if (ad[adi] == s[i]) {
			ans[0].first++;
		}
		if (br[bri] == s[i]) {
			ans[1].first++;
		}
		if (go[goi] == s[i]) {
			ans[2].first++;
		}
		adi = (adi + 1) % 3;
		bri = (bri + 1) % 4;
		goi = (goi + 1) % 6;
	}
	sort(ans, ans + 3,compare);
	cout << ans[0].first << '\n';
	cout << ans[0].second << '\n';
	for (int i = 1; i <3; i++) {
		if (ans[i].first == ans[i - 1].first) {
			cout << ans[i].second << '\n';
		}
		else {
			break;
		}
	}
}