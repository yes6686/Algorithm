import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;


class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = {};
        
        int[] ch = new int[N+2];
        
        for(int stage : stages){
            ch[stage] += 1;
        }
        
        HashMap<Integer, Double> fails = new HashMap<>();
        
        double total = stages.length;
        
        for(int i=1;i<=N;i++){
            if(ch[i]==0){
                fails.put(i,0.);
            }else{
                fails.put(i, ch[i] / total);
                total -= ch[i];
            }
        }
        
       return fails.entrySet().stream().sorted((o1,o2)->o1.getValue().equals(o2.getValue()) ? 
             Integer.compare(o1.getKey(), o2.getKey()) : Double.compare(o2.getValue(), o1.getValue())).mapToInt(HashMap.Entry::getKey).toArray();
    }
}