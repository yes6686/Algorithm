#include <string>
#include <vector>

using namespace std;

int alpha[27];

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++){
        if(i==s.size()-1){
            answer++;
            break;
        }
        int cnt1 = 1;
        int cnt2 = 0;
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]){
                cnt1++;
            }else{
                cnt2++;
            }
            if(cnt1 == cnt2){
                i=j;
                answer++;
                break;
            }
            if(j==s.size()-1) {
                i=j;
                answer++;
            }
        }
    }
    return answer;
}