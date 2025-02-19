
#include <string>
#include <vector>

using namespace std;

int arr[101][101];

int solution(int n, int w, int num) {
    int answer = 0;
    int i = 1, j = 1;
    int s = 1;
    bool check = false; // 지그재그 여부
    int ai = 0, aj = 0;

    // 테이블을 채우는 과정
    while (true) {
        if (!check) {
            arr[i][j] = s;
            if (s == num) {
                ai = i;
                aj = j;
            }
        } else {
            arr[i][w - j + 1] = s;
            if (s == num) {
                ai = i;
                aj = w - j + 1;
            }
        }
        s++;
        if (s > n) break;
        if (j == w) { // 다음 줄로 이동
            i++;
            check = !check; // 방향 전환
            j = 1;
        } else {
            j++;
        }
    }

    // 연속 증가하는 숫자 개수 세기
    while (arr[ai][aj] >= num) {
        answer++;
        ai++;
        if (ai > 100 || arr[ai][aj] == 0) break;
    }

    return answer;
}
