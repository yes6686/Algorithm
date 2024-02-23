#include <iostream>
#include <map>
using namespace std;

int dx[822] = { 2,2,1,1,-1,-1,-2,-2 };
int dy[822] = { -1,1,-2,2,-2,2,-1,1 };

map<string, int>mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	string preS="";
	int check = 0;
	string start;
	for (int i = 0; i < 37; i++) {
		int cc = 0;
		if (i < 36) {
			cin >> s;
			mp[s]++;
			if (mp[s] > 1) {
				check = 1;
			}
		}
		else {
			s = start;
		}
		if (i == 0) {
			start = s;
		}
		if (preS != "") {
			int px = preS[0] - 'A' + 1;
			int py = preS[1]+'0';
			int cx = s[0] - 'A' + 1;
			int cy = s[1] + '0';
			for (int j = 0; j < 8; j++) {
				int nx = px + dx[j];
				int ny = py + dy[j];
				if (nx == cx && ny == cy) {
					cc = 1;
				}
			}
			if (cc == 0) {
				check = 1;
			}
		}		
		preS = s;
	}

	if (!check) {
		cout << "Valid" << "\n";
	}
	else {
		cout << "Invalid" << "\n";
	}
}