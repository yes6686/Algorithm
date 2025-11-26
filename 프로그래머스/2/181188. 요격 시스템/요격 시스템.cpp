#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


priority_queue<pair<int,int>, vector<pair<int,int>>, 
greater<pair<int,int>>>pq;


int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    for(int i=0;i<targets.size();i++){
        pq.push({targets[i][0], targets[i][1]});
    }
    
    int e=pq.top().second;
    pq.pop();
    while(!pq.empty()){
        int ks = pq.top().first;
        int ke = pq.top().second;
        pq.pop();
        if(e <= ks){
            e = ke;
            answer++;
        }else if(ke <= e){
            e = ke;
        }
    }
    
    
    return answer;
}