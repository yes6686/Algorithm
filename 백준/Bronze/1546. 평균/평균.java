import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double[] arr = new double[1001];
        int n =scanner.nextInt();
        double maxValue = 0;
        for(int i=0;i<n;i++){
            arr[i]= scanner.nextDouble();
            if(maxValue < arr[i]){
                maxValue= arr[i];
            }
        }
        double sum = 0;
        for(int i=0;i<n;i++){
            sum += (arr[i]/maxValue)*100.0;
        }
        System.out.println(sum/n);

    }
}
