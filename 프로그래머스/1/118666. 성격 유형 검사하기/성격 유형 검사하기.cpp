#include <string>
#include <vector>

using namespace std;

int arr[26];

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    string s[4] = {"RT", "CF", "JM", "AN"};
    
    for(int i=0;i<survey.size();i++){
        int k = choices[i]-4;
        if(k >0){
            arr[survey[i][1]-'A'] += k;
        }else{
            arr[survey[i][0]-'A'] += -k;            
        }
    }
    
    for(int i=0;i<4;i++){
        char c1 = s[i][0];
        char c2 = s[i][1];
        if(arr[c1-'A'] >= arr[c2-'A']){
            answer+=c1;
        }else{
            answer+=c2;
        }
    }
    
    
    
    return answer;
}