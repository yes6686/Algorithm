#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[20001];
int visited[20001];
bool isBipartite;

void dfs(int node, int color) {
    visited[node] = color;
    for (int next : v[node]) {
        if (visited[next] == 0) {
            dfs(next, 3 - color);
        } else if (visited[next] == color) {
            isBipartite = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        // 그래프 초기화
        for (int i = 1; i <= V; i++) {
            v[i].clear();
            visited[i] = 0;
        }

        // 간선 입력
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        isBipartite = true;

        // 모든 정점에 대해 DFS 수행
        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0 && isBipartite) {
                dfs(i, 1);
            }
        }

        if (isBipartite) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}