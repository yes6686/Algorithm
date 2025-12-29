import java.util.*;

class Solution {
    private static HashMap<String, Integer> hm = new HashMap<>();
    private static HashSet<Integer> hs = new HashSet<>();
    
    public static void combinations(int idx, char[] order, String result){
        if(hs.contains(result.length())){
            hm.put(result, hm.getOrDefault(result,0)+1);
        }
        
        for(int i = idx ; i<order.length;i++){
            combinations(i+1, order, result + order[i]);
        }
        
    }
    
    public String[] solution(String[] orders, int[] course) {
        
        for(int c : course){
            hs.add(c);
        }
        
        for(String o : orders){
            char[] orderArray = o.toCharArray();
            Arrays.sort(orderArray);
            combinations(0, orderArray, "");
        }
        
        // 코스 길이별 최대 빈도 저장
        HashMap<Integer, Integer> maxCount = new HashMap<>();
        
        for(String key : hm.keySet()){
            int cnt = hm.get(key);
            int len = key.length();
            
            if(cnt < 2) continue;
            
            maxCount.put(len, Math.max(maxCount.getOrDefault(len,0),cnt));
        }
        
        List<String> answer = new ArrayList<>();
        
        for(String key : hm.keySet()){
            int len = key.length();
            int cnt = hm.get(key);
            
            if(cnt>=2 && maxCount.getOrDefault(len,0) ==cnt){
                answer.add(key);
            }
        }
        
        Collections.sort(answer);
        
        
        return answer.toArray(new String[0]);
    }
}