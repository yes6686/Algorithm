#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

map<string,pair<int,int>>mp;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    string str = "123456789*0#";
    
    string rp = "#";
    string lp = "*";
   
    int s=0;
    
    for(int i=1;i<=4;i++){
        for(int j=1;j<=3;j++){
            string ss="";
            ss+=str[s++];
            mp[ss] = {i,j};
        }
    }
    
    for(int i=0;i<numbers.size();i++){
        int n = numbers[i];
        if(n== 1 || n== 4 || n== 7){
            lp = to_string(n); 
            answer+="L";
        }else if(n==3 || n==6 || n==9){
            rp = to_string(n);
            answer+="R";
        }else{
            pair<int,int> rpd = mp[rp];
            pair<int,int> lpd = mp[lp];
            pair<int,int> cn = mp[to_string(n)];
            
            if((abs(rpd.first-cn.first) + abs(rpd.second - cn.second)) > 
              (abs(lpd.first-cn.first) + abs(lpd.second - cn.second))){
                lp = to_string(n);
                answer+="L";
            }else if(abs(rpd.first-cn.first) + abs(rpd.second - cn.second) < 
              abs(lpd.first-cn.first) + abs(lpd.second - cn.second)){
                rp = to_string(n);
                answer+="R";
            }else{
                if(hand =="right"){
                    rp = to_string(n);
                    answer+="R";
                }else{
                    lp = to_string(n);
                    answer+="L";
                }
            }
        }
    }
    
    return answer;
}