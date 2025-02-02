#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int k = (1<<numbers.size())-1;
    for(int i=0;i<=k;i++){
        int c = 0;
        for(int j=0;j<numbers.size();j++){
            if(i & (1<<j)) {
                c += numbers[j];
            }else{
                c -= numbers[j];
            }
        }
        if(c==target) answer++;
    }
    
    return answer;
}