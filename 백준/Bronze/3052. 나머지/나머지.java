import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] arr = new int[42];
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            int x = sc.nextInt();
            x %= 42;
            if (arr[x] == 0) {
                cnt++;
                arr[x]++;
            }
        }
        System.out.println(cnt);
    }
}
