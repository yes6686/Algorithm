import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n+501];
        for(int i=0;i<n;i++){
            int x= scanner.nextInt();
            arr[100+x]++;
        }

        int v = scanner.nextInt();
        System.out.println(arr[v+100]);
    }
}
