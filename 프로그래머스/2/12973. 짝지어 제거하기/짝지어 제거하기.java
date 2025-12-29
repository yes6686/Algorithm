import java.util.Stack;
class Solution
{
    public int solution(String s)
    {
        Stack<Character> stack = new Stack<>();
        
        int n = s.length();
        
        for(int i=0;i<n;i++){
            char c = s.charAt(i);
            if(stack.empty()) stack.push(c);
            else{
                char f = stack.peek();
                if(c != f) {
                    stack.push(c);
                }else{
                    stack.pop();
                }
            }
        }

        return stack.empty() ? 1: 0;
    }
}