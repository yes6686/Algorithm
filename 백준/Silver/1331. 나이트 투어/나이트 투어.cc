#include <iostream>
#include <map>
using namespace std;

int dx[8] = { 2,2,1,1,-1,-1,-2,-2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };

map<string, int>mp;

int main() {
	string s;
	string preS="";
	int check = 0;
	int sx;
	int sy;
	int lx;
	int ly;
	for (int i = 0; i < 36; i++) {
		int cc = 0;
		cin >> s;
		if (i == 0) {
			sx = s[0] - 'A' + 1;
			sy = s[1] + '0';
		}
		if (i == 35) {
			lx = s[0] - 'A' + 1;
			ly = s[1] + '0';
		}
		mp[s]++;
		if (mp[s] > 1) {
			check = 1;
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
	int cc = 0;
	for (int j = 0; j < 8; j++) {
		int nx = lx + dx[j];
		int ny = ly + dy[j];
		if (nx == sx && ny == sy) {
			cc = 1;
		}
	}

	if (!check && cc) {
		cout << "Valid" << "\n";
	}
	else {
		cout << "Invalid" << "\n";
	}
}