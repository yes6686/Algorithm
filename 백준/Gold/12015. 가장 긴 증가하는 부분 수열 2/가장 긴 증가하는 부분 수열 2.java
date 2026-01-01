import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static List<Integer> dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        dp = new ArrayList<>();
        dp.add(arr[0]);

        for(int i=1;i<n;i++){
            if(arr[i] > dp.get(dp.size()-1)){
                dp.add(arr[i]);
            }else{
                int pos = binary_search(arr[i]);
                dp.set(pos, arr[i]);
            }
        }

        System.out.println(dp.size());
    }

    private static int binary_search(int x) {
        int left = 0;
        int right = dp.size()-1;
        int result = right;

        while(left <= right){
            int mid = (left + right) / 2;
            if(dp.get(mid) >= x){
                right = mid - 1;
                result = mid;
            }else {
                left = mid + 1;
            }
        }
        return result;
    }
}
