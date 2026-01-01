import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";

        String[] num = new String[numbers.length];

        for(int i=0;i<numbers.length;i++){
            num[i] = String.valueOf(numbers[i]);
        }

        Arrays.sort(num, (a, b) ->
                (b + a).compareTo(a + b));
        
        if(num[0].equals("0")) return "0";

        for(String n : num){
            answer+=n;
        }

        
        return answer;
    }
}