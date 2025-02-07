#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int s_by;

bool compare(vector<int> a, vector<int> b){
    return a[s_by] < b[s_by];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    for(int i=0;i<data.size();i++){
        int d;
        if(ext=="code"){
            d = data[i][0];
        }else if(ext=="date"){ 
            d = data[i][1];
        }else if(ext == "maximum"){         
            d = data[i][2];
        }else{  
            d = data[i][3];
        }
        if(d < val_ext){
            answer.push_back(data[i]);
        }
    }
    if(sort_by=="code"){
        s_by=0;   
    }else if(sort_by=="date"){
        s_by=1;   
    }else if(sort_by=="maximum"){
        s_by=2;    
    }else{
        s_by=3;   
    }
    sort(answer.begin(),answer.end(), compare);
    
    return answer;
}