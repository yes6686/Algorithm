import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        String s = scanner.nextLine();
        int cnt=0;
        int check =0;
        for(int i=0;i<s.length();i++){

            if(s.charAt(i)==' ' && check==1){
                check=0;
                cnt++;
            }

            if(s.charAt(i)!=' '){
                check=1;
            }
        }
        if(check==1){
            cnt++;
        }
        System.out.println(cnt);
    }
}