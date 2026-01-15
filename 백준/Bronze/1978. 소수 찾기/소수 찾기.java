import java.util.*;

public class Main {

    public static boolean isPrime(int x){

        if(x==1) return false;
        if(x==2) return true;

        for(int i=2;i<=x/2;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int answer = 0;
        for(int i=0;i<n;i++){
            int x = sc.nextInt();
            if(isPrime(x)){
                answer++;
            }
        }
        System.out.println(answer);
    }
}
