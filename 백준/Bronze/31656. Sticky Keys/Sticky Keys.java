import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        char[] arr = s.toCharArray();

        StringBuilder sb = new StringBuilder();
        sb.append(arr[0]);

        for (int i = 1; i < s.length(); i++) {
            if (arr[i] == arr[i - 1]) {
                continue;
            }
            sb.append(arr[i]);
        }

        System.out.println(sb);
    }
}