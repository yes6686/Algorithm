#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

vector<int>v[20001];
int visited[20001];
int check = 0;
void dfs(int a) {
    for (int i = 0; i < v[a].size(); i++) {
        int k = v[a][i];
        if (visited[k] == 1) {
            if (visited[a] == 1) {
                check = 1;
            }
        }
        else if (visited[k] == -1) {
            if (visited[a] == -1) {
                check = 1;
            }
        }
        else {
            if (visited[a] == 1) {
                visited[k] = -1;
            }
            else {
                visited[k] = 1;
            }
            dfs(k);
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
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        check = 0;
        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                dfs(i);
            }
        }

        if (check == 1) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= V; i++) {
            v[i].clear();
        }
    }
}