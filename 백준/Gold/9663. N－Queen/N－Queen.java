
import java.util.Scanner;

public class Main {

    private static int N;
    private static int answer;
    private static boolean[] width;
    private static boolean[] dra1;
    private static boolean[] dra2;

    private static void bt(int row){

        if(row == N){
            answer++;
            return;
        }

        for(int col=0;col<N;col++){
            if(!width[col] && !dra1[row + col] && !dra2[row - col + N]){
                width[col] = true;
                dra1[row + col] = true;
                dra2[row - col + N] = true;
                bt(row+1);
                width[col] = false;
                dra1[row + col] = false;
                dra2[row - col + N] = false;
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        N = n;
        width = new boolean[n];
        dra1 = new boolean[n*2];
        dra2 = new boolean[n*2];
        bt(0);
        System.out.println(answer);
        sc.close();
    }
}
