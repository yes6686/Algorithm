import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cntA = 0;
        int cntB = 0;
        for(int i=0;i<n;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            if(a>b){
                cntA++;
            }else if(a<b){
                cntB++;
            }
        }
        System.out.println(cntA+" "+cntB);
    }
}
