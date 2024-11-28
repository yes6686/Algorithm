#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    // 돗자리 크기 내림차순 정렬
    sort(mats.begin(), mats.end(), greater<int>());

    int rows = park.size();
    int cols = park[0].size();

    // park 배열을 숫자로 변환 (0: 빈자리, 1: 사람이 있는 자리)
    vector<vector<int>> arr(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (park[i][j] == "-1" ? 0 : 1);
        }
    }

    // 가장 큰 돗자리부터 시도
    for (int k : mats) {
        for (int a = 0; a <= rows - k; a++) {
            for (int b = 0; b <= cols - k; b++) {
                bool canPlace = true;
                for (int h = a; h < a + k && canPlace; h++) {
                    for (int f = b; f < b + k; f++) {
                        if (arr[h][f] == 1) {
                            canPlace = false;
                            break;
                        }
                    }
                }
                if (canPlace) {
                    return k; // 가장 큰 돗자리 크기 반환
                }
            }
        }
    }

    return -1; // 깔 수 있는 돗자리가 없음
}
