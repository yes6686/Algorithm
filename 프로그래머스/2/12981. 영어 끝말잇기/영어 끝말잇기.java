import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        HashSet<String> set = new HashSet<>();

        int idx = 1;
        int cnt = 1;
        set.add(words[0]);
        
        for(int i=1;i<words.length;i++){
            idx = (idx+1);
            if(idx > n) {
                idx = 1;
                cnt++;
            }
            
            if(set.contains(words[i]) || 
               words[i].charAt(0) != words[i-1].charAt(words[i-1].length()-1)){
                answer[0] = idx;
                answer[1] = cnt;
                return answer;
            }
            set.add(words[i]);
        }
        
        return answer;
    }
}