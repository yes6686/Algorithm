import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);

        int h = scanner.nextInt();
        int m = scanner.nextInt();
        int t = scanner.nextInt();

        if(m+t>=60){
            h+=(m+t)/60;
            m=(m+t)%60;
            if(h>=24){
                h-=24;
            }
        }else{
            m+=t;
        }

        System.out.println(h+" "+m);
    }
}
