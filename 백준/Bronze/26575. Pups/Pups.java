import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            double d=sc.nextDouble();
            double f=sc.nextDouble();
            double p=sc.nextDouble();
            String s=String.format("%.2f",d*f*p);
            System.out.print("$");
            System.out.println(s);
        }
    }
}