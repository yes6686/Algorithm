
#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int p_len = p.size();
    long long p_value = stoll(p); // 기준값을 정수로 변환

    for (int i = 0; i <= t.size() - p_len; i++) {
        string sub_str = t.substr(i, p_len); // 부분 문자열 추출
        long long sub_value = stoll(sub_str); // 정수 변환

        if (sub_value <= p_value) {
            answer++;
        }
    }

    return answer;
}
