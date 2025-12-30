import java.util.*;

class Solution {
    
    private static HashMap<String,String> hm = new HashMap<>();
    private static HashMap<String,Integer> enrollSales = new HashMap<>();
    
    public static void dfs(String s, int p){        
        int pp = p / 10;
        int myp = p - pp;
        
        enrollSales.put(s, enrollSales.getOrDefault(s,0)+myp);
        
        if(hm.get(s).equals("-") || pp <=0){ 
            return;
        }
        dfs(hm.get(s), pp);
    }
    
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        
        for(int i=0;i<enroll.length;i++){
            hm.put(enroll[i],referral[i]);
            enrollSales.put(enroll[i],0);
        }
        
        for(int i=0;i<seller.length;i++){
            dfs(seller[i], amount[i]*100);
        }
        
        int[] result = new int[enroll.length];
        
        for(int i=0;i<result.length;i++){
            result[i] = enrollSales.get(enroll[i]);
        }
        
        return result;
    }
}