#include <string>
#include <vector>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4] = {1,-1,0,0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    for(int i=0;i<4;i++){
        int nx = h + dx[i];
        int ny = w + dy[i];
        if(nx<0 || ny<0 || nx>=board.size() || ny >= board.size()) continue;
        if(board[h][w] == board[nx][ny]) answer++;

    }
    
    return answer;
}