#include <iostream>
#include <string>
#include <vector>

using namespace std;
int visited[101][101][20001];

pair<int,int>arr[101];
pair<int,int>dis[101];

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer=0;
    
    for(int i=0;i<points.size();i++){
        dis[i+1].first = points[i][0];
        dis[i+1].second = points[i][1];
    }

    for(int i=0;i<routes.size();i++){
        arr[i+1].first = points[routes[i][0]-1][0];
        arr[i+1].second = points[routes[i][0]-1][1];
        visited[arr[i+1].first][arr[i+1].second][0]++;
    }
    
        for(int i=1;i<=routes.size();i++){
            int t=1;
            for(int j=1;j<routes[i-1].size();j++){
                int ei = dis[routes[i-1][j]].first;
                int ej = dis[routes[i-1][j]].second;
                while(true){
                    int si = arr[i].first;
                    int sj = arr[i].second;
                    if(si==ei && sj==ej) break;
                    if(si!=ei){
                        if(si > ei){
                            si--;
                        }else if(si < ei){
                            si++;
                        }
                        arr[i].first=si; 
                        visited[si][sj][t]++;
                    }else{
                        if(sj!=ej){
                            if(sj > ej){
                                sj--;
                            }else if(sj < ej){
                                sj++;
                            }
                            arr[i].second=sj;
                            visited[si][sj][t]++;
                        }
                    } 
                    t++;
                }
            }
        }
        
     for(int t=0;t<=11001;t++){
        for(int r=1;r<=100;r++){
            for(int c=1;c<=100;c++){
                if(visited[r][c][t] >= 2){
                    answer++;
                }
            }
        }
    }
    
    
    return answer;
}