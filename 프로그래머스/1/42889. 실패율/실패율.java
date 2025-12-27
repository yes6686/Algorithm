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
        
        List<Integer> list = new ArrayList<>(fails.keySet());
        list.sort((o1,o2)->Double.compare(fails.get(o2), fails.get(o1)));
        
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}