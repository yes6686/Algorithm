#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr[51][51];
int dp[51][51];

int solution(vector<int> mats, vector<vector<string>> park) {
    int rows = park.size();
    int cols = park[0].size();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(park[i][j]=="-1"){
                arr[i][j]=1;
            }else{
                arr[i][j]=0;
            }
        }
    }
    int maxAns = -1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i==0 || j==0 || arr[i][j]==0) continue;
            arr[i][j] = min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]})+1;
            maxAns = max(maxAns,arr[i][j]);
        }    
    }
    int answer = -1;

    sort(mats.rbegin(),mats.rend());
    
    for(int mat : mats){
        if(mat <= maxAns){
            answer = mat;
            break;
        }
    }
    
    return answer;
    
}
