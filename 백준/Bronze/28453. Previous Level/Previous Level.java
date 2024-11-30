import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine()); // 레벨의 개수
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int level;
		while (n-- > 0) {
			level = Integer.parseInt(st.nextToken()); // 레벨
			
			if (level >= 300) { // 레벨이 300이상이면
				sb.append(1);
			} else if (300 > level && level >= 275) { // 레벨이 300미만이고 275이상이면
				sb.append(2);
			} else if (275 > level && level >= 250) { // 레벨이 275미만이고 250이상이면
				sb.append(3);
			} else { // 그 외
				sb.append(4);
			}
			
			sb.append(" ");
		}
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}