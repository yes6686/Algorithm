import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n= scanner.nextInt();
        for(int i=0;i<n;i++){
            String s = scanner.next();
            System.out.println(s.charAt(0)+""+s.charAt(s.length()-1));
        }
    }
}
