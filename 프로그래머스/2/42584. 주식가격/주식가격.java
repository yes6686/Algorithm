import java.util.Stack;
class Solution {
    public int[] solution(int[] prices) {
        
        Stack<Integer> stack = new Stack<>();
        
        int n = prices.length;
        int[] answer = new int[n];
        for(int i=0; i<n;i++){
            while(!stack.empty() && prices[i] < prices[stack.peek()]){
                int j = stack.pop();
                answer[j] = i - j;
            }
            stack.push(i);
        }
        
        while(!stack.empty()){
            int k = stack.pop();
            answer[k] = n-1 -k;
        }
        
        return answer;
    }
}