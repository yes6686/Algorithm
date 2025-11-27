#include <string>
#include <vector>

using namespace std;

vector<int>v[201];
int visited[201];

void dfs(int x){
    if(visited[x]==1) return;
    visited[x]=1;
    for(int i=0;i<v[x].size();i++){
        int k =v[x][i];
        dfs(k);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[0].size();j++){
            if(i!=j) {
                if(computers[i][j]==1){
                    v[i].push_back(j);
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(visited[i]==0) {
            answer++;
            dfs(i);
        }
    }
    
    return answer;
}