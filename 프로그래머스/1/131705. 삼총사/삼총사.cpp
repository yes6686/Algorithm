#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    
    sort(number.begin(),number.end());
    for(int i=0;i<number.size()-2;i++){
        for(int j=i+1;j<number.size()-1;j++){
            int s = number[i] + number[j];
            if(s>0) break;
            for(int t=j+1;t<number.size();t++){
                if(number[i] + number[j] + number[t] > 0) break;
                if(number[i] + number[j] + number[t] == 0) answer++;
            }
        }
    }
    
    return answer;
}