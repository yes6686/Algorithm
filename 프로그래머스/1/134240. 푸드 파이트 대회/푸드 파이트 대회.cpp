#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string r = "";
    for(int i=1;i<food.size();i++){
        int k = food[i]/2;
        for(int j=0;j<k;j++){
            r+=to_string(i);
        }
    }
    answer+=r;
    reverse(r.begin(),r.end());    
    answer+='0';
    answer+=r;
    return answer;
}