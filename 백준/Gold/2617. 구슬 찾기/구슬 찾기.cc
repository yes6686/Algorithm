#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> heavy[101]; // 자신보다 무거운 구슬
vector<int> light[101]; // 자신보다 가벼운 구슬
bool visited[101];
int n, m;

int dfs(int node, vector<int> graph[]) {
    int cnt = 0;
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            cnt += dfs(next, graph);
        }
    }
    return cnt + 1; // 자기 자신 포함
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        heavy[b].push_back(a); // b보다 무거운 구슬: a
        light[a].push_back(b); // a보다 가벼운 구슬: b
    }

    int mid = (n + 1) / 2;
    int result = 0;

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        int heavy_count = dfs(i, heavy) - 1;

        memset(visited, false, sizeof(visited));
        int light_count = dfs(i, light) - 1;

        if (heavy_count >= mid || light_count >= mid) {
            result++;
        }
    }

    cout << result << '\n';
}
