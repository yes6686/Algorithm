#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<int>arr;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    for(int i=0;i<score.size();i++){
        arr.push_back(score[i]);
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<arr.size();i++){
        if((arr.size()-i)%m==0){
            answer+=(arr[i]*m);
            i+=(m-1);
        }
    }
    
    return answer;
}