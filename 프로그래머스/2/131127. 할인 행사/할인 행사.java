import java.util.*;

class Solution {
    private boolean isMatch(HashMap<String, Integer> hm,
                           HashMap<String, Integer> ch){
        for(String key : hm.keySet()){
            if(!hm.get(key).equals(ch.getOrDefault(key,0))){
                return false;
            }
        }
        return true;
    }
    
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        HashMap<String, Integer> hm = new HashMap<>();
        
        for(int i=0;i<want.length;i++){
            hm.put(want[i], number[i]);
        }
        
        HashMap<String, Integer> ch = new HashMap<>();
        for(int i=0;i<10;i++){
            ch.put(discount[i], ch.getOrDefault(discount[i],0)+1);
        }
        if(isMatch(hm,ch)) answer++;
        
        for(int i=10;i<discount.length;i++){
            ch.put(discount[i], ch.getOrDefault(discount[i],0)+1);
            ch.put(discount[i-10], ch.getOrDefault(discount[i-10],0)-1);
            
         if(isMatch(hm,ch)) answer++;
            
        }
        
        
        
        return answer;
    }
}