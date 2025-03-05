#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0;i<timelogs.size();i++){
        int check=1;
        int s = startday;
        for(int j=0;j<timelogs[i].size();j++){
            if(s!=6 && s!=7){
                int ss = schedules[i]+10;
                if(ss%100 >= 60){
                    ss+=40;
                }
                if(ss < timelogs[i][j]){
                    check=0;
                    break;
                }
            }
            s = (s+1)%8;
            if(s==0) s=1;
        }
        if(check==1) answer++;
    }
    
    return answer;
}