#include <string>
#include <vector>

using namespace std;

int arr[100001];

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for(int i=0;i<section.size();i++){
        arr[section[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==1){
            answer++;
            for(int j=i;j<i+m && j<=n;j++){
                arr[j]=0;
            }
        }
    }
    
    return answer;
}