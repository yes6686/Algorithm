import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.next();

        int t = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='A' || s.charAt(i)=='B'|| s.charAt(i)=='C'){
                t+=3;
            }
            else if(s.charAt(i)=='D' || s.charAt(i)=='E' || s.charAt(i)=='F'){
                t+=4;
            }
            else if(s.charAt(i)=='G' || s.charAt(i)=='H' || s.charAt(i)=='I'){
                t+=5;
            }
            else if(s.charAt(i)=='J' || s.charAt(i)=='K' || s.charAt(i)=='L'){
                t+=6;
            }
            else if(s.charAt(i)=='M' || s.charAt(i)=='N' || s.charAt(i)=='O'){
                t+=7;
            }
            else if(s.charAt(i)=='P' || s.charAt(i)=='Q' || s.charAt(i)=='R' || s.charAt(i)=='S'){
                t+=8;
            }
            else if(s.charAt(i)=='T' || s.charAt(i)=='U' || s.charAt(i)=='V'){
                t+=9;
            }
            else if(s.charAt(i)=='W' || s.charAt(i)=='X' || s.charAt(i)=='Y' || s.charAt(i)=='Z'){
                t+=10;
            }else{
                t+=11;
            }
        }
        System.out.println(t);
    }
}
