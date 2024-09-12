#include <iostream>
#include <vector>
using namespace std;


int main() {
	
	vector<vector<int>> arr(2001, vector<int>(2001,0));

	int N = 2;
	while (N-- > 0) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;

		x += 1000;
		y += 1000;
		x1 += 1000;
		y1 += 1000;

		for (int i = y; i < y1; ++i) {
			for (int k = x; k < x1; ++k) {
				arr[i][k] = 1;
			}
		}
	}

	int x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;

	x += 1000;
	y += 1000;
	x1 += 1000;
	y1 += 1000;

	for (int i = y; i < y1; ++i) {
		for (int k = x; k < x1; ++k) {
			arr[i][k] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 2001; ++i) {
		for (int k = 0; k < 2001; ++k) {
			if (arr[i][k] == 1) ++cnt;
		}
	}

	cout << cnt;
	return 0;
}