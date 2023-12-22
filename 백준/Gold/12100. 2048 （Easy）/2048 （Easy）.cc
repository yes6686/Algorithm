#include <iostream>
#include <vector>
using namespace std;
int arr[21][21];
int n;

int maxBlock = -1;

void go(vector<vector<int>>v, int depth, int dir) {

	if (dir == 1) { // 상
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j]) {
					for (int t = i + 1; t < n; t++) {
						if (v[t][j]) {
							if (v[i][j] == v[t][j]) {
								v[i][j] *= 2;
								v[t][j] = 0;
							}
							break;
						}
					}
				}
				else if (v[i][j] == 0) {
					for (int t = i + 1; t < n; t++) {
						int check = 1;
						if (v[t][j]) {
							if (t == n - 1) {
								v[i][j] = v[t][j];
								v[t][j] = 0;
                                check=0;
							}
							else {
								for (int h = t + 1; h <n; h++) {
									if (v[h][j]) {
										if (v[h][j] == v[t][j]) {
											v[i][j] = v[t][j] * 2;
											v[t][j] = 0;
											v[h][j] = 0;
										}
										else {
											v[i][j] = v[t][j];
											v[t][j] = 0;
										}
										check = 0;
										break;
									}

								}
							}
							if (check == 1) {
								v[i][j] = v[t][j];
								v[t][j] = 0;
							}
							break;
						}
					}
				}
			}
		}
	}
	if (dir == 2) { // 하
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < n; j++) {
				if (v[i][j]) {
					for (int t = i - 1; t >= 0; t--) {
						if (v[t][j]) {
							if (v[i][j] == v[t][j]) {
								v[i][j] *= 2;
								v[t][j] = 0;
							}
							break;
						}
					}
				}
				else if (v[i][j] == 0) {
					for (int t = i - 1; t >= 0; t--) {
						int check = 1;
						if (v[t][j]) {
							if (t == 0) {
								v[i][j] = v[t][j];
								v[t][j] = 0;
                                check=0;
							}
							else {
								for (int h = t - 1; h >=0; h--) {
									if (v[h][j]) {
										if (v[h][j] == v[t][j]) {
											v[i][j] = v[t][j] * 2;
											v[t][j] = 0;
											v[h][j] = 0;
										}
										else {
											v[i][j] = v[t][j];
											v[t][j] = 0;
										}
										check = 0;
										break; 
									}

								}
							}
							if (check == 1) {
								v[i][j] = v[t][j];
								v[t][j] = 0;
							}
							break;
						}
					}
				}
			}
		}
	}
	if (dir == 3) { // 좌
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (v[i][j]) {
					for (int t = j + 1; t < n; t++) {
						if (v[i][t]) {
							if (v[i][j] == v[i][t]) {
								v[i][j] *= 2;
								v[i][t] = 0;
							}
							break;
						}
					}
				}
				else if (v[i][j] == 0) {
					for (int t = j + 1; t < n; t++) {
						int check = 1;
						if (v[i][t]) {
							if (t == n - 1) {
								v[i][j] = v[i][t];
								v[i][t] = 0;
                                check=0;
							}
							else {
								
								for (int h = t +1; h < n ; h++) {
									if (v[i][h]) {
										if (v[i][h] == v[i][t]) {
											v[i][j] = v[i][t] * 2;
											v[i][t] = 0;
											v[i][h] = 0;
										}
										else {
											v[i][j] = v[i][t];
											v[i][t] = 0;
										}
										check = 0;
										break;
										
									}

								}
							}
							if (check == 1) {
								v[i][j] = v[i][t];
								v[i][t] = 0;
							}
							break;
						}
					}
				}
			}
		}
	}
	if (dir == 4) { // 우
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > 0; j--) {
				if (v[i][j]) {
					for (int t = j - 1; t >= 0; t--) {
						if (v[i][t]) {
							if (v[i][j] == v[i][t]) {
								v[i][j] *= 2;
								v[i][t] = 0;
							}
							break;
						}
					}
				}
				else if (v[i][j] == 0) {
					for (int t = j - 1; t >= 0; t--) {
						int check = 1;
						if (v[i][t]) {
							if (t == 0) {
								v[i][j] = v[i][t];
								v[i][t] = 0;
                                check=0;
							}
							else {							
								for (int h = t-1; h >=0; h--) {
									if (v[i][h]) {
										if (v[i][h] == v[i][t]) {
											v[i][j] = v[i][t] * 2;
											v[i][t] = 0;
											v[i][h] = 0;
										}
										else {
											v[i][j] = v[i][t];
											v[i][t] = 0;
										}
										check = 0;
										break;
									}

								}
								
							}
							if (check == 1) {
								v[i][j] = v[i][t];
								v[i][t] = 0;
							}
							break;
						}
						
					}
				}
			}
		}
	}
	if (depth == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				maxBlock = max(maxBlock, v[i][j]);
			}
		}
		return;
	}

	
	go(v, depth + 1, 1);
	go(v, depth + 1, 2);
	go(v, depth + 1, 3);
	go(v, depth + 1, 4);

}

vector<vector<int>>V;

vector<int>v1[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			v1[i].push_back(arr[i][j]);
		}
		V.push_back(v1[i]);
	}
	go(V, 1, 1);
	go(V, 1, 2);
	go(V, 1, 3);
	go(V, 1, 4);

	cout << maxBlock << '\n';
}