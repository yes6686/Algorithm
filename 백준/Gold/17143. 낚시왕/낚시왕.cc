#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct shake {
	int speed=0;
	int di=0;
	int weight=0;
};

struct shake1 {
	int xx,yy;
	int sp;
	int dd;
	int ww;
};


int arr[101][101];
int arr1[101][101];


// r,c : 위치 , s : 속력 , d : 이동 방향
// z : 크기
//d 
// (1 : 위) (2 : 아래) (3 : 오른쪽) (4 : 왼쪽)
int R, C, M;
int cnt = 0;
shake Shake[101][101];
shake1 Shake1[10001];
void go(int y) {
	int ss = 0;
	if (y == C + 1) {
		cout << cnt << '\n';
		return;
	}

	for (int i = 1; i <= R; i++) {
		if (arr[i][y] == 1) {
			arr1[i][y] = 0;
			arr[i][y] = 0;
			cnt+=Shake[i][y].weight;
			//cout << i << " , " << y << '\n';
			//cout << "Shake.weight : " << Shake[i][y].weight << '\n';
			break;
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j]) {
				if (Shake[i][j].di == 1 || Shake[i][j].di == 2) { // 아래
					int sp = Shake[i][j].speed;
					int curr = i;
					int didi = Shake[i][j].di;
					//if (sp == 0) continue;
					while (sp--) {
						if (didi == 2) {
							if (curr + 1 <= R) {
								curr++;
							}
							else {
								didi = 1;
								curr--;
							}
						}
						else {
							if (curr - 1 >= 1) {
								curr--;
							}
							else {
								didi = 2;
								curr++;
							}
						}
					}
					arr1[i][j] = 0;
					Shake1[ss].xx = curr;
					Shake1[ss].yy = j;
					Shake1[ss].dd = didi;
					Shake1[ss].sp = Shake[i][j].speed;
					Shake1[ss].ww = Shake[i][j].weight;
					ss++;

				}
				else if (Shake[i][j].di == 3 || Shake[i][j].di == 4) { // 오른쪽
					int sp = Shake[i][j].speed;
					int curr = j;
					int didi = Shake[i][j].di;
					//if (sp == 0) continue;
					while (sp--) {
						if (didi == 3) {
							if (curr + 1 <= C) {
								curr++;
							}
							else {
								didi = 4;
								curr--;
							}
						}
						else {
							if (curr - 1 >= 1) {
								curr--;
							}
							else {
								didi = 3;
								curr++;
							}
						}
					}
					arr1[i][j] = 0;
					Shake1[ss].xx = i;
					Shake1[ss].yy = curr;
					Shake1[ss].dd = didi;
					Shake1[ss].sp = Shake[i][j].speed;
					Shake1[ss].ww = Shake[i][j].weight;
					ss++;
				}
			}
		}
	}
	for (int i = 0; i < ss; i++) {
		if (arr1[Shake1[i].xx][Shake1[i].yy] == 1) {
			if (Shake[Shake1[i].xx][Shake1[i].yy].weight > Shake1[i].ww) continue;

			Shake[Shake1[i].xx][Shake1[i].yy].weight = Shake1[i].ww;
			Shake[Shake1[i].xx][Shake1[i].yy].speed = Shake1[i].sp;
			Shake[Shake1[i].xx][Shake1[i].yy].di = Shake1[i].dd;


		}
		else {
			Shake[Shake1[i].xx][Shake1[i].yy].weight = Shake1[i].ww;
			Shake[Shake1[i].xx][Shake1[i].yy].speed = Shake1[i].sp;
			Shake[Shake1[i].xx][Shake1[i].yy].di = Shake1[i].dd;
			arr1[Shake1[i].xx][Shake1[i].yy] = 1;
		}


		

	}

	//memset(Shake1, 0, sizeof(Shake1));

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			arr[i][j] = arr1[i][j];
		}
	}
	memset(arr1, 0, sizeof(arr1));
	go(y + 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		arr[r][c] = 1;
		Shake[r][c].speed = s;
		Shake[r][c].di = d;
		Shake[r][c].weight = z;
	}
	go(1);

}