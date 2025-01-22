#include <iostream>
#include <string.h>
using namespace std;

pair<int, string>str[17];
int visited[17];
int n;
int minPrice = -1;
int ans[27];
int ch[27];

void go(int d) {

	for (int i = d; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			go(i + 1);
			visited[i] = 0;
		}
	}
	int price = 0;
	int check = 0;
	memset(ch, 0, sizeof(ch));
	for (int i = 0; i < n; i++) {
		if (visited[i] == 1) {
			price += str[i].first;
			for (int j = 0; j < str[i].second.size(); j++) {
				ch[str[i].second[j] - 'A']++;
			}
		}
	}
	for (int j = 0; j < 27; j++) {
		if (ans[j]>0) {
			if (ch[j] == 0) {
				check = 1;
				break;
			}
			if (ans[j] > ch[j]) {
				check = 1;
				break;
			}
		}
	}
	if (check == 0) {
		if (minPrice == -1) {
			minPrice = price;
		}
		else {
			minPrice = min(minPrice, price);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		ans[s[i] - 'A']++;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		string st = "";
		string sk;
		cin >> str[i].first;
		cin >> sk;
		for (int j = 0; j < sk.size(); j++) {
			if (ans[sk[j] - 'A']) {
				st += sk[j];
			}
		}
		str[i].second = st;
	}
	go(0);
	cout << minPrice << '\n';
}