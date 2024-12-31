#include <iostream>
#include <vector>
using namespace std;

int v, e;
vector<int> vec[20001];
int graph[20001];
string ans;

bool dfs(int s) {
    for (int neighbor : vec[s]) {
        if (graph[neighbor] == 0) {  // 미방문 노드
            graph[neighbor] = 3 - graph[s];  // 1 -> 2, 2 -> 1
            if (!dfs(neighbor)) return false;
        } else if (graph[neighbor] == graph[s]) {  // 같은 그룹에 속하면 이분 그래프 아님
            return false;
        }
    }
    return true;
}

void solve() {
    for (int i = 1; i <= v; i++) {
        if (graph[i] == 0) {  // 방문하지 않은 컴포넌트만 탐색
            graph[i] = 1;  // 시작 노드 그룹 설정
            if (!dfs(i)) {
                ans = "NO";
                return;
            }
        }
    }
    ans = "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cin >> v >> e;

        // 초기화
        for (int i = 1; i <= v; i++) {
            vec[i].clear();
            graph[i] = 0;
        }

        // 그래프 입력
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        // 이분 그래프 판별
        solve();

        cout << ans << '\n';
    }
    return 0;
}
