import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int findVal = sc.nextInt();
        int[][] arr = new int[n][n];

        int i=0, j=0;
        int currState = 1; // 1: 아래, 2: 오른쪽, 3: 위쪽, 4: 왼쪽
        int val = n*n;
        while(true){
            if(val == 0) break;

            if(currState==2){ // 오른쪽
                arr[i][j] = val--;
                if(j==n-1 || arr[i][j+1]>0) {
                    i--;
                    currState = 3;
                }
                else {
                    j++;
                }
            }else if(currState==1){ // 아래
                arr[i][j] = val--;
                if(i==n-1 || arr[i+1][j]>0) {
                    j++;
                    currState = 2;
                }
                else i++;
            }else if(currState==4){ // 왼쪽
                arr[i][j] = val--;
                if(j==0 || arr[i][j-1]>0) {
                    i++;
                    currState = 1;
                }
                else j--;
            }else{ // 위쪽
                arr[i][j] = val--;
                if(i==0 || arr[i-1][j]>0) {
                    j--;
                    currState = 4;
                }
                else i--;
            }
        }

        int findI=0, findJ=0;
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                System.out.print(arr[a][b]+" ");
                if(arr[a][b]==findVal){
                    findI = a+1;
                    findJ = b+1;
                }
            }
            System.out.println();
        }
        System.out.println(findI+" "+findJ);

        sc.close();
    }
}
