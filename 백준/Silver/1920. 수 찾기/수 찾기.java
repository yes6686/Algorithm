import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        int m = sc.nextInt();
        for(int i=0;i<m;i++){
            int x = sc.nextInt();
            int s = 0;
            int e = n-1;
            int check = 0;
            while(s<=e){
                int mid = (s+e)/2;
                if(arr[mid] == x){
                    check=1;
                    break;
                }
                else if(arr[mid] > x){
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }
            if(check==1) {
                System.out.println(1);
            }else{
                System.out.println(0);
            }
        }
    }
}