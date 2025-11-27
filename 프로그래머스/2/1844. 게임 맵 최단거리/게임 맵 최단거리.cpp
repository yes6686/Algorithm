#include<vector>
#include <queue>
using namespace std;

queue<pair<int,int>>q;
int arr[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int answer = -1;
int n=0,m=0;

void bfs(){
    int visited[101][101] ={0};
    visited[0][0]=1;
    while(!q.empty()){
        int kx = q.front().first;
        int ky = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = kx+dx[i];
            int ny = ky+dy[i];
            if(nx<0 || ny<0 ||nx>=n || ny>=m) continue;
            if(arr[nx][ny]==1 || visited[nx][ny]) continue;
            visited[nx][ny] = visited[kx][ky]+1;
            if(nx==n-1 && ny==m-1){
                answer = visited[nx][ny];
                return;
            }
            q.push({nx,ny});
        }
    }
}

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j]==0) arr[i][j]=1;
        }
    }
    
    q.push({0,0});
    bfs();
    
    return answer;
}