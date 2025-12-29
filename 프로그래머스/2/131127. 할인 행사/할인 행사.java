import java.util.*;

class Solution {
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
        int check = 1;
        for(int j=0;j<want.length;j++){
            if(hm.get(want[j])!=ch.get(want[j])) {
                check=0; 
                break;
            }
        }
        if(check==1) answer++;
        
        for(int i=10;i<discount.length;i++){
            ch.put(discount[i], ch.getOrDefault(discount[i],0)+1);
            ch.put(discount[i-10], ch.getOrDefault(discount[i-10],0)-1);
            
            check = 1;
            for(int j=0;j<want.length;j++){
                if(hm.get(want[j])!=ch.get(want[j])) {
                    check=0; 
                    break;
                }
            }
            if(check==1) answer++;
            
        }
        
        
        
        return answer;
    }
}