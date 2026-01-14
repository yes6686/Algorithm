import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Stack<Integer> st = new Stack<>();
        int k = sc.nextInt();
        for(int i=0;i<k;i++){
            int x = sc.nextInt();
            if(x==0){
                if(!st.isEmpty()){
                    st.pop();
                }
            }else{
                st.add(x);
            }
        }

        int answer = 0;
        while(!st.isEmpty()){
            answer += st.pop();
        }
        System.out.println(answer);
    }
}
