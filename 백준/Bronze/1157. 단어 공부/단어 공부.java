import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = new int[26];
        String str = scanner.next();

        for(int i=0;i<str.length();i++){
            if(str.charAt(i)>='a' && str.charAt(i)<='z') {
                arr[str.charAt(i) - 'a']++;
            }else{
                arr[str.charAt(i) - 'A']++;
            }
        }
        int maxCnt= 0;
        int maxAlpha=0;
        for(int i=0;i<26;i++){
            if(maxCnt < arr[i]){
                maxCnt=arr[i];
                maxAlpha =i;
            }
        }
        int check = 0;
        for(int i=0;i<26;i++){
            if(maxAlpha !=i && maxCnt == arr[i]){
                check=1;
                break;
            }
        }
        if(check==0){
            System.out.println((char)('A'+maxAlpha));
        }else{
            System.out.println('?');
        }
    }
}