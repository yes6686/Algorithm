class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        
        int[] check = new int[10];
        
        for(int i=0;i<numbers.length;i++){
            if(check[numbers[i]]==0) check[numbers[i]] = 1;
        }
        
        for(int i=1;i<=9;i++){
            if(check[i]==0) answer += i;
        }
        
        return answer;
    }
}