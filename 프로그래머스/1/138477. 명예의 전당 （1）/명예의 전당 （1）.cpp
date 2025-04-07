#include <string>
#include <vector>

using namespace std;

vector<int>arr;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    arr.push_back(score[0]);
    answer.push_back(score[0]);
    for(int i=1;i<score.size();i++){
        
        if(arr.size() < k){
            arr.push_back(score[i]);
        }
        else if(arr[arr.size()-1] < score[i]){
            arr[arr.size()-1] = score[i]; 
        }
        for(int i=arr.size()-1;i>0;i--){
            if(arr[i] > arr[i-1]){
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
            }else{
                break;
            }
        }
        answer.push_back(arr[arr.size()-1]);
        
    }
    
    return answer;
    
    
}