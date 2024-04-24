import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N=scanner.nextInt();
        int M=scanner.nextInt();

        if(N*100>=M) {
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    }
}