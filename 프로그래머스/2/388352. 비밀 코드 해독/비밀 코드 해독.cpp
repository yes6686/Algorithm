#include <string>
#include <vector>

using namespace std;

int visited[31];
int arr[10][31];

int c[11];
int answer=0;
int N;

int qS;

void bt(int d,int n){
    
    if(n==5){
        int check=1;
        
        for(int i=0;i<qS;i++){
            int cnt = 0;
            for(int j=1;j<=N;j++){
                if(visited[j]==1 && arr[i][j]==1) cnt++;
            }
            if(cnt!=c[i]){
                check=0;
                break;
            }
        }
        if(check==1){
            answer++;
        }
        return;
    }
    
    for(int i=d;i<=N;i++){
        if(visited[i]==0){ 
            visited[i]=1;
            bt(i+1, n+1);   
            visited[i]=0;
        }
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    N=n;
    for(int i=0;i<ans.size();i++){
        c[i]=ans[i];
    }
    
    qS= q.size();
    
    for(int i=0;i<qS;i++){
        for(int j=0;j<5;j++){
            arr[i][q[i][j]]=1;
        }
    }
    
    bt(1,0);
    
    return answer;
}