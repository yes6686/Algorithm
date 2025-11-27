#include <string>
#include <vector>
#include <queue>
using namespace std;

int arr[101][101];
int visited[101][101][2];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<pair<int,int>,int>>q;
int check=0;
int ans = -1;

void bfs(int x,int y, int n, int m){
    q.push({{x,y},0});
    visited[x][y][0]=1;
    while(!q.empty()){
        int kx = q.front().first.first;
        int ky = q.front().first.second;
        int kk = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = kx+dx[i];
            int ny = ky+dy[i];
            int nk = kk;
            if(nx<0 || ny<0|| nx>=n || ny>=m) continue;
            if(arr[nx][ny]==2)  nk =1;
            if(arr[nx][ny]==1||visited[nx][ny][nk]) continue;
            visited[nx][ny][nk]= visited[kx][ky][kk]+1;
            if(arr[nx][ny]==3){
                if(kk==1){
                    ans = visited[kx][ky][kk]+1;
                    return;
                }
            }
            q.push({{nx,ny},nk});
        }
    }
}

int solution(vector<string> maps) {
    int si=0,sj=0;
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(maps[i][j]=='S'){
                si = i;
                sj = j;
            }else if(maps[i][j]=='O'){
                arr[i][j]=0;
            }else if(maps[i][j]=='L'){
                arr[i][j]=2;
            }else if(maps[i][j]=='E'){
                arr[i][j]=3;
            }else if(maps[i][j]=='X'){
                arr[i][j]=1;
            }
        }
    }
    
    bfs(si,sj,maps.size(),maps[0].size());
    if(ans==-1){
        return ans;
    }else{
        return ans-1;
    }
}