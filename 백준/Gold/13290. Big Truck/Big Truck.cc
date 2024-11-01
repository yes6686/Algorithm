#include <iostream>
#include <queue>
#define INF 999999999
using namespace std;

int n, m, a, b, c;
int t[101], dis[101], it[101];
vector<pair<int, int>>mat[101];

void solve() {
    for (int i = 1; i < 101; i++)
        dis[i] = INF;
    priority_queue<pair<int, int>>pq;
    dis[1] = 0;
    it[1] = t[1];
    pq.push({ 0,1 });
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int ver = pq.top().second;
        int cnt = it[ver];
        pq.pop();
        for (int i = 0; i < mat[ver].size(); i++) {
            int next_ver = mat[ver][i].first;
            int p = mat[ver][i].second;
            int plus = t[next_ver];
            if (dis[next_ver] > dist + p) {
                dis[next_ver] = dist + p;
                it[next_ver] = cnt + plus;
                pq.push({ -dis[next_ver],next_ver });
            }
            else if (dis[next_ver] == dist + p) {
                it[next_ver] = max(it[next_ver], cnt + plus);
                pq.push({ -dis[next_ver],next_ver });
            }
        }
    }
    if (dis[n] == INF)
        cout << "impossible";
    else
        cout << dis[n] << ' ' << it[n];
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mat[a].push_back({ b,c });
        mat[b].push_back({ a,c });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}