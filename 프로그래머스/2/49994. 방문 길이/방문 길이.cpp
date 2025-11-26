#include <string>
#include <map>
using namespace std;

map<pair<pair<int,int>,int>,int>mpx;
map<pair<int,pair<int,int>>,int>mpy;

int solution(string dirs) {
    int answer = 0;
    
    int a = 0;
    int b = 0;
    
    for(int i=0;i<dirs.size();i++){
        if(dirs[i]=='U'){
            if(a ==5) continue;
            if(mpx[{{a,a+1},b}]==0 && mpx[{{a+1,a},b}]==0){
                mpx[{{a,a+1},b}]=1;
                mpx[{{a+1,a},b}]=1;
                answer++;
            }
            a++;
        }else if(dirs[i]=='D'){
            if(a ==-5) continue;
            if(mpx[{{a,a-1},b}]==0 && mpx[{{a-1,a},b}]==0){
                mpx[{{a,a-1},b}]=1;
                mpx[{{a-1,a},b}]=1;
                answer++;
            }
            a--;
        }else if(dirs[i]=='R'){
            if(b ==5) continue;
            if(mpy[{a,{b+1,b}}]==0 && mpy[{a,{b,b+1}}]==0){
                mpy[{a,{b+1,b}}]=1;
                mpy[{a,{b,b+1}}]=1;
                answer++;
            }
            b++;
        }else{
            if(b==-5) continue;
            if(mpy[{a,{b-1,b}}]==0 && mpy[{a,{b,b-1}}]==0){
                mpy[{a,{b-1,b}}]=1;
                mpy[{a,{b,b-1}}]=1;
                answer++;
            }
            b--;
        }
    }
    
    
    return answer;
}