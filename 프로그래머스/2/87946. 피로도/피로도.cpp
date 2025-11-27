#include <string>
#include <vector>

using namespace std;

int n=0;
int arr[8][2];
int visited[8];
int answer = 0;

void bt(int d, int x, int cnt){
    
    answer = max(answer,cnt);
    for(int i=0;i<n;i++){
        if(visited[i]==1) continue;
        if(x >= arr[i][0]){
            visited[i]=1;
            bt(i+1, x-arr[i][1],cnt+1);
            visited[i]=0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    
    for(int i=0;i<dungeons.size();i++){
        for(int j=0;j<dungeons[i].size();j++){
            arr[i][j] = dungeons[i][j];
        }
    }
    bt(0,k,0);
    
    return answer;
}