#include <string>
#include <vector>

using namespace std;

int arr1[5] = {1,2,3,4,5};
int arr2[8] = {2, 1, 2, 3, 2, 4,2,5};
int arr3[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int sum1=0;
    int sum2=0;
    int sum3=0;
    
    for(int i=0;i<answers.size();i++){
        if(answers[i] == arr1[i%5]) sum1++;
        if(answers[i] == arr2[i%8]) sum2++;
        if(answers[i] == arr3[i%10]) sum3++;
    }
    
    int maxSum = max(sum1, max(sum2,sum3));
    if(maxSum==sum1) answer.push_back(1);
    if(maxSum==sum2) answer.push_back(2);
    if(maxSum==sum3) answer.push_back(3);
    
    return answer;
}