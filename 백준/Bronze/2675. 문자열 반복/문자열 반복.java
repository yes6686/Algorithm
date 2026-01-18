import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for(int i=0;i<T;i++){
            int r = sc.nextInt();
            String s = sc.next();
            for(int j=0;j<s.length();j++){
                char c = s.charAt(j);
                for(int k=0;k<r;k++){
                    System.out.print(c);
                }
            }
            System.out.println();
        }
    }
}