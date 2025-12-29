import java.util.Stack;

class Solution {
    
    public int solution(String s) {
        int answer = 0;
        
        int n = s.length();
        
        s+=s;
        
        for(int i=0;i<n;i++){
            Stack<Character> stack = new Stack<>();
            int check =1;
            for(int j=i;j<i+n;j++){
                char c = s.charAt(j);
                if(c=='(' || c=='[' || c=='{'){
                    stack.push(c);
                }else{
                    if(stack.empty()){
                        check=0;
                        break;
                    }else{
                        char e = stack.peek();
                        if((e=='(' && c==')') || (e=='[' && c==']') || 
                          (e=='{' && c=='}')){
                            stack.pop();
                                continue;
                        }else{
                            check=0;
                            break;
                        }
                    }
                }
            }
            if(stack.empty() && check==1) answer++;
        }
    
        
        return answer;
    }
}