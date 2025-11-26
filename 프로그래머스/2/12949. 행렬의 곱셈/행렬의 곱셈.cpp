#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    answer.assign(arr1.size(), vector<int>(arr2[1].size(),0));
    
    int r = arr1.size();
    int c = arr2[0].size();
    int k = arr2.size();
    
    for(int i=0;i<r;i++){
        for(int t=0;t<c;t++){
            int sum=0;
            for(int j=0;j<k;j++){
                answer[i][t] += (arr1[i][j] * arr2[j][t]);
            }
        }
    }
    
    return answer;
}