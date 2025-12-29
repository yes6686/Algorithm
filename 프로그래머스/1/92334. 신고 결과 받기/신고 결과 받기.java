import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        
        HashMap<String, Integer> hm = new HashMap<>();
        HashSet<String> hs = new HashSet<>();
        Set<String> list = new HashSet<>();
        
        for(int i=0;i<report.length;i++){
            String[] parts = report[i].split(" ");
            if(!hs.contains(parts[0]+" "+parts[1])){
                hs.add(parts[0]+" "+parts[1]);
                hm.put(parts[1], hm.getOrDefault(parts[1],0)+1);
            }
        }
        
        for(String s : hm.keySet()){
            if(hm.get(s) >=k) list.add(s);
        }
        
        List<Integer> answer = new ArrayList<>();
        
        for(int j=0;j<id_list.length;j++){
            int cnt=0;
            for(String s : list){
                if(hs.contains(id_list[j]+" "+s)) cnt++;
            }
            answer.add(cnt);
        }
        
        
        
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}