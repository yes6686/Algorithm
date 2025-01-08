
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // 입력을 받기 위한 Scanner 객체 생성

        int h = scanner.nextInt(); // 현재 시(hour)
        int m = scanner.nextInt(); // 현재 분(minute)
        int t = scanner.nextInt(); // 추가할 조리 시간(분)

        // 총 분 계산
        m += t; 
        h += m / 60; // 분을 시간으로 변환
        m %= 60; // 남은 분

        // 24시간 초과 시 조정
        if (h >= 24) {
            h -= 24;
        }

        System.out.println(h + " " + m); // 결과 출력
    }
}
