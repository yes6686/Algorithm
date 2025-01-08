import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = new int[101];
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        for(int i=0;i<m;i++){
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int k = scanner.nextInt();
            for(int j=a;j<=b;j++){
                arr[j]=k;
            }
        }
        for(int i=1;i<=n;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
