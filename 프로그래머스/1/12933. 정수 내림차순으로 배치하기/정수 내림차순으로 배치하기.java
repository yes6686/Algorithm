import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        
        String[] numbers = String.valueOf(n).split("");
        Arrays.sort(numbers, Collections.reverseOrder());
        
        StringBuilder sb = new StringBuilder();
        for(String num : numbers){
            sb.append(num);
        }
        
        return Long.parseLong(sb.toString());
    }
}