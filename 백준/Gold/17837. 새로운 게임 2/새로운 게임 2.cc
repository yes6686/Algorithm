#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int arr[14][14];

struct ed {
	int x, y;
	int cn;
	int di;
};
int n, k;
int cnt = 0;
ed Ed[11];

vector<pair<int, int >> v[14][14];
int check = 1;
void go() {
	while (1) {
		if (cnt > 1000) {
			cout << -1;
			break;
		}

		for (int i = 1; i <= k; i++) {
			int a = Ed[i].x;
			int b = Ed[i].y;
			int c = Ed[i].cn;
			int d = Ed[i].di;

			if (d == 1) {  // ->
				if (b + 1 > n) {
					Ed[i].di = 2;
					v[a][b][0].second = 2;
					int siz = v[a][b].size();
					int nextsiz = 0;
					if (b - 1 >= 1) {
						if (arr[a][b - 1] == 0) {
							siz = v[a][b].size();
							nextsiz = v[a][b - 1].size();
							for (int t = 0; t < siz - c + 1; t++) {
								v[a][b - 1].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
								int s = v[a][b][c - 1 + t].first;
								Ed[s].y -= 1;
								Ed[s].cn = nextsiz + t + 1;
							}
							for (int t = 0; t < siz - c + 1; t++) {
								v[a][b].pop_back();
							}

						}
						else if (arr[a][b - 1] == 1) {
							siz = v[a][b].size();
							nextsiz = v[a][b - 1].size();
							for (int t = 0; t < siz - c + 1; t++) {
								int kk1 = v[a][b].back().first;
								int kk2 = v[a][b].back().second;
								v[a][b - 1].push_back({ kk1,kk2 });
								Ed[kk1].y -= 1;
								Ed[kk1].cn = nextsiz + t + 1;
								v[a][b].pop_back();
							}
						}
					}
				}
				else {
					int siz = v[a][b].size();
					int nextsiz = 0;
					if (arr[a][b + 1] == 0) {
						siz = v[a][b].size();
						nextsiz = v[a][b + 1].size();
						for (int t = 0; t < siz - c + 1; t++) {
							v[a][b + 1].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
							int s = v[a][b][c - 1 + t].first;
							Ed[s].y += 1;
							Ed[s].cn = nextsiz + t + 1;
						}
						for (int t = 0; t < siz - c + 1; t++) {
							v[a][b].pop_back();
						}
					}
					else if (arr[a][b + 1] == 1) {

						siz = v[a][b].size();
						nextsiz = v[a][b + 1].size();
						for (int t = 0; t < siz - c + 1; t++) {
							int kk1 = v[a][b].back().first;
							int kk2 = v[a][b].back().second;
							v[a][b + 1].push_back({ kk1,kk2 });
							Ed[kk1].y += 1;
							Ed[kk1].cn = nextsiz + t + 1;
							v[a][b].pop_back();
						}

					}
					else if (arr[a][b + 1] == 2) {
						Ed[i].di = 2;
						v[a][b][0].second = 2;
						if (b - 1 >= 1) {
							if (arr[a][b - 1] == 0) {
								siz = v[a][b].size();
								nextsiz = v[a][b - 1].size();
								for (int t = 0; t < siz - c + 1; t++) {
									v[a][b - 1].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
									int s = v[a][b][c - 1 + t].first;
									Ed[s].y -= 1;
									Ed[s].cn = nextsiz + t + 1;
								}
								for (int t = 0; t < siz - c + 1; t++) {
									v[a][b].pop_back();
								}
							}
							else if (arr[a][b - 1] == 1) {
								siz = v[a][b].size();
								nextsiz = v[a][b - 1].size();
								for (int t = 0; t < siz - c + 1; t++) {
									int kk1 = v[a][b].back().first;
									int kk2 = v[a][b].back().second;
									v[a][b - 1].push_back({ kk1,kk2 });
									Ed[kk1].y -= 1;
									Ed[kk1].cn = nextsiz + t + 1;
									v[a][b].pop_back();
								}
							}
						}
					}
				}

			}
			else if (d == 2) { // <-
				if (b - 1 <= 0) {
					Ed[i].di = 1;
					v[a][b][0].second = 1;
					int siz = v[a][b].size();
					int nextsiz = 0;
					if (b + 1 <= n) {
						if (arr[a][b + 1] == 0) {
							siz = v[a][b].size();
							nextsiz = v[a][b + 1].size();
							for (int t = 0; t < siz - c + 1; t++) {
								v[a][b + 1].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
								int s = v[a][b][c - 1 + t].first;
								Ed[s].y += 1;
								Ed[s].cn = nextsiz + t + 1;
							}
							for (int t = 0; t < siz - c + 1; t++) {
								v[a][b].pop_back();
							}
						}
						else if (arr[a][b + 1] == 1) {
							siz = v[a][b].size();
							nextsiz = v[a][b + 1].size();
							for (int t = 0; t < siz - c + 1; t++) {
								int kk1 = v[a][b].back().first;
								int kk2 = v[a][b].back().second;
								v[a][b + 1].push_back({ kk1,kk2 });
								Ed[kk1].y += 1;
								Ed[kk1].cn = nextsiz + t + 1;
								v[a][b].pop_back();
							}
						}
					}

				}
				else { // b - 1>=1
					int siz = v[a][b].size();
					int nextsiz = 0;
					if (arr[a][b - 1] == 0) {
						siz = v[a][b].size();
						nextsiz = v[a][b - 1].size();
						for (int t = 0; t < siz - c + 1; t++) {
							v[a][b - 1].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
							int s = v[a][b][c - 1 + t].first;
							Ed[s].y -= 1;
							Ed[s].cn = nextsiz + t + 1;
						}
						for (int t = 0; t < siz - c + 1; t++) {
							v[a][b].pop_back();
						}
					}
					else if (arr[a][b - 1] == 1) {

						siz = v[a][b].size();
						nextsiz = v[a][b - 1].size();
						for (int t = 0; t < siz - c + 1; t++) {
							int kk1 = v[a][b].back().first;
							int kk2 = v[a][b].back().second;
							v[a][b - 1].push_back({ kk1,kk2 });
							Ed[kk1].y -= 1;
							Ed[kk1].cn = nextsiz + t + 1;
							v[a][b].pop_back();
						}

					}
					else if (arr[a][b - 1] == 2) {
						Ed[i].di = 1;
						v[a][b][0].second = 1;
						if (b + 1 <= n) {
							if (arr[a][b + 1] == 0) {
								siz = v[a][b].size();
								nextsiz = v[a][b + 1].size();
								for (int t = 0; t < siz - c + 1; t++) {
									v[a][b + 1].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
									int s = v[a][b][c - 1 + t].first;
									Ed[s].y += 1;
									Ed[s].cn = nextsiz + t + 1;
								}
								for (int t = 0; t < siz - c + 1; t++) {
									v[a][b].pop_back();
								}
							}
							else if (arr[a][b + 1] == 1) {
								siz = v[a][b].size();
								nextsiz = v[a][b + 1].size();
								for (int t = 0; t < siz - c + 1; t++) {
									int kk1 = v[a][b].back().first;
									int kk2 = v[a][b].back().second;
									v[a][b + 1].push_back({ kk1,kk2 });
									Ed[kk1].y += 1;
									Ed[kk1].cn = nextsiz + t + 1;
									v[a][b].pop_back();
								}
							}
						}
					}
				}
			}
			else if (d == 3) { // up
				if (a - 1 <= 0) {
					Ed[i].di = 4;
					v[a][b][0].second = 4;
					int siz = v[a][b].size();
					int nextsiz = 0;
					if (a + 1 <= n) {
						if (arr[a + 1][b] == 0) {
							siz = v[a][b].size();
							nextsiz = v[a + 1][b].size();
							for (int t = 0; t < siz - c + 1; t++) {
								v[a + 1][b].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
								int s = v[a][b][c - 1 + t].first;
								Ed[s].x += 1;
								Ed[s].cn = nextsiz + t + 1;
							}
							for (int t = 0; t < siz - c + 1; t++) {
								v[a][b].pop_back();
							}
						}
						else if (arr[a + 1][b] == 1) {
							siz = v[a][b].size();
							nextsiz = v[a + 1][b].size();
							for (int t = 0; t < siz - c + 1; t++) {
								int kk1 = v[a][b].back().first;
								int kk2 = v[a][b].back().second;
								v[a + 1][b].push_back({ kk1,kk2 });
								Ed[kk1].x += 1;
								Ed[kk1].cn = nextsiz + t + 1;
								v[a][b].pop_back();
							}
						}
					}
				}
				else {
					int siz = v[a][b].size();
					int nextsiz = 0;
					if (arr[a - 1][b] == 0) {
						siz = v[a][b].size();
						nextsiz = v[a - 1][b].size();
						for (int t = 0; t < siz - c + 1; t++) {
							v[a - 1][b].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
							int s = v[a][b][c - 1 + t].first;
							Ed[s].x -= 1;
							Ed[s].cn = nextsiz + t + 1;
						}
						for (int t = 0; t < siz - c + 1; t++) {
							v[a][b].pop_back();
						}
					}
					else if (arr[a - 1][b] == 1) {

						siz = v[a][b].size();
						nextsiz = v[a - 1][b].size();
						for (int t = 0; t < siz - c + 1; t++) {
							int kk1 = v[a][b].back().first;
							int kk2 = v[a][b].back().second;
							v[a - 1][b].push_back({ kk1,kk2 });
							Ed[kk1].x -= 1;
							Ed[kk1].cn = nextsiz + t + 1;
							v[a][b].pop_back();
						}

					}
					else if (arr[a - 1][b] == 2) {
						Ed[i].di = 4;
						v[a][b][0].second = 4;
						if (a + 1 <= n) {
							if (arr[a + 1][b] == 0) {
								siz = v[a][b].size();
								nextsiz = v[a + 1][b].size();
								for (int t = 0; t < siz - c + 1; t++) {
									v[a + 1][b].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
									int s = v[a][b][c - 1 + t].first;
									Ed[s].x += 1;
									Ed[s].cn = nextsiz + t + 1;
								}
								for (int t = 0; t < siz - c + 1; t++) {
									v[a][b].pop_back();
								}
							}
							else if (arr[a + 1][b] == 1) {
								siz = v[a][b].size();
								nextsiz = v[a + 1][b].size();
								for (int t = 0; t < siz - c + 1; t++) {
									int kk1 = v[a][b].back().first;
									int kk2 = v[a][b].back().second;
									v[a + 1][b].push_back({ kk1,kk2 });
									Ed[kk1].x += 1;
									Ed[kk1].cn = nextsiz + t + 1;
									v[a][b].pop_back();
								}
							}
						}
					}
				}
			}
			else if (d == 4) { // down
				if (a + 1 > n) {
					Ed[i].di = 3;
					v[a][b][0].second = 3;
					int siz = v[a][b].size();
					int nextsiz = 0;
					if (a - 1 >= 1) {
						if (arr[a - 1][b] == 0) {
							siz = v[a][b].size();
							nextsiz = v[a - 1][b].size();
							for (int t = 0; t < siz - c + 1; t++) {
								v[a - 1][b].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
								int s = v[a][b][c - 1 + t].first;
								Ed[s].x -= 1;
								Ed[s].cn = nextsiz + t + 1;
							}
							for (int t = 0; t < siz - c + 1; t++) {
								v[a][b].pop_back();
							}
						}
						else if (arr[a - 1][b] == 1) {
							siz = v[a][b].size();
							nextsiz = v[a - 1][b].size();
							for (int t = 0; t < siz - c + 1; t++) {
								int kk1 = v[a][b].back().first;
								int kk2 = v[a][b].back().second;
								v[a - 1][b].push_back({ kk1,kk2 });
								Ed[kk1].x -= 1;
								Ed[kk1].cn = nextsiz + t + 1;
								v[a][b].pop_back();
							}
						}
					}
				}
				else {
					int siz = v[a][b].size();
					int nextsiz = 0;
					if (arr[a + 1][b] == 0) {
						siz = v[a][b].size();
						nextsiz = v[a + 1][b].size();
						for (int t = 0; t < siz - c + 1; t++) {
							v[a + 1][b].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
							int s = v[a][b][c - 1 + t].first;
							Ed[s].x += 1;
							Ed[s].cn = nextsiz + t + 1;
						}
						for (int t = 0; t < siz - c + 1; t++) {
							v[a][b].pop_back();
						}
					}
					else if (arr[a + 1][b] == 1) {

						siz = v[a][b].size();
						nextsiz = v[a + 1][b].size();
						for (int t = 0; t < siz - c + 1; t++) {
							int kk1 = v[a][b].back().first;
							int kk2 = v[a][b].back().second;
							v[a + 1][b].push_back({ kk1,kk2 });
							Ed[kk1].x += 1;
							Ed[kk1].cn = nextsiz + t + 1;
							v[a][b].pop_back();
						}

					}
					else if (arr[a + 1][b] == 2) {
						Ed[i].di = 3;
						v[a][b][0].second = 3;
						if (a - 1 >= 1) {
							if (arr[a - 1][b] == 0) {
								siz = v[a][b].size();
								nextsiz = v[a - 1][b].size();
								for (int t = 0; t < siz - c + 1; t++) {
									v[a - 1][b].push_back({ v[a][b][c - 1 + t].first,v[a][b][c - 1 + t].second });
									int s = v[a][b][c - 1 + t].first;
									Ed[s].x -= 1;
									Ed[s].cn = nextsiz + t + 1;
								}
								for (int t = 0; t < siz - c + 1; t++) {
									v[a][b].pop_back();
								}
							}
							else if (arr[a - 1][b] == 1) {
								siz = v[a][b].size();
								nextsiz = v[a - 1][b].size();
								for (int t = 0; t < siz - c + 1; t++) {
									int kk1 = v[a][b].back().first;
									int kk2 = v[a][b].back().second;
									v[a - 1][b].push_back({ kk1,kk2 });
									Ed[kk1].x -= 1;
									Ed[kk1].cn = nextsiz + t + 1;
									v[a][b].pop_back();
								}
							}
						}
					}
				}
			}
			if (v[a][b].size() >= 4) {
				cout << cnt << '\n';
				check = 0;
				break;
			}
			if (v[a][b - 1].size() >= 4) {
				cout << cnt+1  << '\n';
				check = 0;
				break;
			}
			if (v[a][b + 1].size() >= 4) {
				cout << cnt+1  << '\n';
				check = 0;
				break;
			}
			if (v[a + 1][b].size() >= 4) {
				cout << cnt+1  << '\n';
				check = 0;
				break;
			}
			if (v[a - 1][b].size() >= 4) {
				cout << cnt+1  << '\n';
				check = 0;
				break;
			}
		}
		cnt++;
		if (check == 0) break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j ++) {
			cin >> arr[i][j];
		}
	}
	int x, y, d;
	for (int i = 1; i <= k; i++) {
		cin >> Ed[i].x >> Ed[i].y >> Ed[i].di;
		v[Ed[i].x][Ed[i].y].push_back({ i,Ed[i].di });
		Ed[i].cn = 1;
	}

	go();
}