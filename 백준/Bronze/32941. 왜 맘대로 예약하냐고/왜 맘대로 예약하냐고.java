import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt(); // 몇 교시까지 있는가.
        int X = sc.nextInt(); // 예약한 교시.

        int N = sc.nextInt(); // 조원의 수

        int attendance = 0; // X교시에 참석 가능한 인원

        for (int i = 0; i < N; i++) {
            int K = sc.nextInt(); // 조원이 참석 가능한 교시의 개수
            boolean canAttend = false;

            for (int j = 0; j < K; j++) {
                int clazz = sc.nextInt(); // 가능한 교시 입력 받기
                if (clazz == X) { // 입력 받은 값이 예약한 교시와 같다면
                    canAttend = true; // 참석 가능 여부 : true
                }
            }
            if (canAttend) { // 참석 가능하다면
                attendance++; // 참석 가능한 인원 1명 증가
            }
        }

        if (attendance == N) { // 참석 가능 인원이 전체 조원수와 같다면
            System.out.println("YES"); // 전원 참석 가능
        } else {
            System.out.println("NO");
        }
    }
}