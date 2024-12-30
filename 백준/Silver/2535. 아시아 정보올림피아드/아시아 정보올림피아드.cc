#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    int country;
    int studentId;
    int score;
};

bool compare(const Student &a, const Student &b) {
    return a.score > b.score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Student> students(n);
    vector<int> countryCount(101, 0);

    for (int i = 0; i < n; i++) {
        cin >> students[i].country >> students[i].studentId >> students[i].score;
    }

    sort(students.begin(), students.end(), compare);

    int totalCnt = 0;
    for (const auto &student : students) {
        if (countryCount[student.country] >= 2) {
            continue;
        }

        countryCount[student.country]++;
        cout << student.country << " " << student.studentId << '\n';
        totalCnt++;

        if (totalCnt >= 3) {
            break;
        }
    }

    return 0;
}
