import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String,Integer> hm = new HashMap<>();
        
        for(int i=0;i<completion.length;i++){
            if(hm.containsKey(completion[i])) {
                hm.put(completion[i], hm.get(completion[i])+1);
            }else{
                hm.put(completion[i],1);    
            }
        }
        
        for(int i=0;i<participant.length;i++){
            if(hm.containsKey(participant[i])){
                hm.put(participant[i], hm.get(participant[i])-1);
                if(hm.get(participant[i])==0){
                    hm.remove(participant[i]);
                }
            }else{
                answer = participant[i];
                break;
            }
        }
        
        return answer;
    }
}