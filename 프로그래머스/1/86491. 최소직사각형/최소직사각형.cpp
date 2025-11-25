#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {

    int maxW = 0;
    int maxH = 0;
    for(int i=0;i<sizes.size();i++){
        int a = sizes[i][0];
        int b = sizes[i][1];
        if(a>b){
            maxW = max(maxW,a);
            maxH = max(maxH,b);
        }else{
            maxW = max(maxW,b);
            maxH = max(maxH,a);
        }
    }
    
    return maxW*maxH;
}