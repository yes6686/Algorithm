#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int sx = 0;
    int sy = 0;
    
    int r = park.size();
    int c = park[0].size();
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(park[i][j]=='S'){
                sx = i;
                sy = j;
            }
        }
    }
    cout<<sx<<" , "<<sy<<'\n';
    for(int i=0;i<routes.size();i++){
        int d = int(routes[i][2])-'0';
        int check=0;
        int nx =0 ,ny = 0;
        if(routes[i][0]=='E'){ // 동
            for(int j=1;j<=d;j++){ 
                nx = sx;
                ny = sy + j;
                if(nx < 0 || ny <0 || nx >=park.size() || ny >=park[0].size()) {
                    check=1;
                    break;
                }
                if(park[nx][ny]=='X') {
                    check=1;
                    break;
                }
            }
        }else if(routes[i][0]=='W'){ // 서
             for(int j=1;j<=d;j++){
                nx = sx;
                ny = sy - j;
                if(nx < 0 || ny <0 || nx >=park.size() || ny >=park[0].size()) {
                    check=1;
                    break;
                }
                if(park[nx][ny]=='X') {
                    check=1;
                    break;
                }
            } 
        }else if(routes[i][0]=='S'){ // 남
             for(int j=1;j<=d;j++){
                nx = sx + j;
                ny = sy;
                if(nx < 0 || ny <0 || nx >=park.size() || ny >=park[0].size()) {
                    check=1;
                    break;
                }
                if(park[nx][ny]=='X') {
                    check=1;
                    break;
                }
            }
            
        }else{ // 북
             for(int j=1;j<=d;j++){
                nx = sx - j;
                ny = sy;
                if(nx < 0 || ny <0 || nx >=park.size() || ny >=park[0].size()) {
                    check=1;
                    break;
                }
                if(park[nx][ny]=='X') {
                    check=1;
                    break;
                }
            }
        }
        if(check) continue;
        sx = nx;
        sy = ny;
    }
    answer.push_back(sx);
    answer.push_back(sy);
    return answer;
}