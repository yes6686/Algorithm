import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt(); // 브실이가 푼 문제 수
        int X = sc.nextInt();

        int people = 0;
        for(int i=K-X; i<K+X+1; i++) {
            if(i < A || i > B) continue;
            people++;
        }

        if(people == 0) System.out.print("IMPOSSIBLE");
        else System.out.print(people);
    }
}