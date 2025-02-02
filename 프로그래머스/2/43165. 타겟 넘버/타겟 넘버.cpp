#include <string>
#include <vector>

using namespace std;

int arr[21];
int ans =0;

void dfs(int d,int n,int target,int size){
    if(size==d){
        if(n==target){
            ans++;
        }
        return;
    }
    dfs(d+1,n+arr[d],target,size);
    dfs(d+1,n-arr[d],target,size);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    for(int i=0;i<numbers.size();i++){
        arr[i]= numbers[i];
    }
    dfs(0,0,target,numbers.size());
    answer = ans;
    return answer;
}