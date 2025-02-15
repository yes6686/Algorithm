#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int minR =51;
    int minC =51;
    int maxR =0;
    int maxC =0;

    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].size();j++){
            if(wallpaper[i][j]=='#'){
                minR = min(minR,i);
                minC = min(minC,j);
                maxR = max(maxR,i);
                maxC = max(maxC,j);
            }
        }
    }
    answer.push_back(minR);
    answer.push_back(minC);
    answer.push_back(maxR+1);
    answer.push_back(maxC+1);
    return answer;
      
}