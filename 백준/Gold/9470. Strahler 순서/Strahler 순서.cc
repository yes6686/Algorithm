#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int arr[MAX];
int inDegree[MAX];
vector<int>v[MAX];
vector<int>n[MAX];
queue<int>q;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int k, m, p;
		cin >> k >> m >> p;
		int a, b;
		for (int i = 0; i < p; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			inDegree[b]++;
		}

		for (int i = 1; i <= m; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
				arr[i] = 1;
			}
			
		}
		for (int i = 1; i <= m; i++) {
			int k = q.front();
			q.pop();
			for (int j = 0; j < v[k].size(); j++) {
				int h = v[k][j];
				inDegree[h]--;
				n[h].push_back(arr[k]);

				if (inDegree[h] == 0) {
					q.push(h);
					int maxIndex = 0;
					for (int t = 0; t < n[h].size(); t++) {
						int w = n[h][t];
						if (maxIndex < w) {
							maxIndex = w;
						}
					}
					int cnt = 0;
					for (int t = 0; t < n[h].size(); t++) {
						if (n[h][t] == maxIndex) cnt++;
					}
					if (cnt > 1) {
						arr[h] = maxIndex + 1;
					}
					else if(cnt==1) {
						arr[h] = maxIndex;
					}
					
				}
			}
			
		}

		int maxResult = -1;
		for (int i = 1; i <= m; i++) {
			if (maxResult < arr[i]) {
				maxResult = arr[i];
			}
		}
		cout << k << ' ' << maxResult << '\n';
		for (int i = 1; i <= m; i++) {
			v[i].clear();
			arr[i] = 0;
			inDegree[i] = 0;
            n[i].clear();
		}
	}

}