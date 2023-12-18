#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int,int>x, pair<int,int>y) {
		return x > y;
	}
};

priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

int main() {
	int n;
	cin >> n;
	int startTime, endTime;
	for (int i = 0; i < n; i++) {
		cin >> startTime >> endTime;
		pq.push({ startTime,endTime });
	}
	int togetherTime = 0;
	int ph = 10;
	int pm = 0;
	int max = 0;
	startTime = pq.top().first;
	endTime = pq.top().second;
	int hour = startTime / 100;
	int minute = startTime % 100;
	if (ph < hour) {
		togetherTime = 60 * (hour - ph);
		togetherTime += minute - pm - 10;
	}
	if (ph == hour && pm < minute && (minute - pm - 10 > 0)) {
		togetherTime = minute - pm - 10;
	}
	if (max < togetherTime) {
		max = togetherTime;
	}
	ph = endTime / 100;
	pm = endTime % 100;
	pq.pop();
	while (!pq.empty()) {
		startTime = pq.top().first;
		endTime = pq.top().second;
		hour = startTime / 100;
		minute = startTime % 100;
		if (ph < hour ) {
			togetherTime = 60 * (hour - ph);
			togetherTime += minute - pm - 20;
		}
		if (ph == hour && pm < minute && (minute - pm - 20>0)) {
			togetherTime = minute - pm - 20;
		}
		if (max < togetherTime) {
			max = togetherTime;
		}
		if (ph < endTime / 100 || (ph==endTime/100 && pm < endTime % 100)) {
			ph = endTime / 100;
			pm = endTime % 100;
		}
		pq.pop();
	}
	if (ph < 22 && !(ph==21 && pm>50)) {
		togetherTime = 60 * (22 - ph);
		togetherTime -= (pm + 10);
	}

	if (max < togetherTime) {
		max = togetherTime;
	}
	cout << max;
}