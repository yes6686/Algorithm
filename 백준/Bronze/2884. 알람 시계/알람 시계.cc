#include <iostream>
using namespace std;

int main() {

	int h, m;
	cin >> h >> m;
	int ah,am;
	if (m - 45 < 0 && h-1>=0) {
		am = 60 - (45 - m);
		ah = h - 1;
	}
	else if(m-45>=0){
		ah = h;
		am = m-45;
	}
	else if (m - 45 < 0 && h - 1 < 0) {
		ah = 23;
		am = 60 - (45 - m);
	}
	else {
		ah = 0;
		am = 0;
	}
	
	cout << ah <<" " << am;
}