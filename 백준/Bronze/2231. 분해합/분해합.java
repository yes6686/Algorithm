import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        
        boolean check = false;
        for(int i=1;i<=n;i++){
            int s = i;
            int k = i;
            while(k > 0){
                s += k%10;
                k/=10;
            }
            if(s==n){
                System.out.println(i);
                check = true;
                break;
            }
        }
        if(!check) System.out.println(0);
    }
}