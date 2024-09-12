#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<vector<int>> v(201, vector<int>(201, 0));
	int n;
	cin >> n;

	int x, y, x1, y1;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y >> x1 >> y1;
		x += 100;
		y += 100;
		x1 += 100;
		y1 += 100;

		if (i % 2 != 0) {
			for (int j = y; j < y1; ++j) {
				for (int k = x; k < x1; ++k) v[j][k] = 1;
			}
		}
		else {
			for (int j = y; j < y1; ++j) {
				for (int k = x; k < x1; ++k) v[j][k] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 201; ++i) {
		for (int k = 0; k < 201; ++k) {
			if (v[i][k] == 2) ++cnt;
		}
	}

	cout << cnt;
	return 0;

}