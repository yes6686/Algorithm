import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int v = sc.nextInt();

        int k = a - b;
        v-=a;
        if(v%k==0){
            System.out.println(v/k+1);
        }else{
            int d = 0;
            if(v%k!=0) d++;
            System.out.println(v/k+1 + d);
        }
    }
}