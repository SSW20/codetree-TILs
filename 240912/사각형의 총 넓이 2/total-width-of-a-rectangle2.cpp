#include <iostream>
#include <vector>
using namespace std;


int main() {
	
	int N;
	cin >> N;

	vector<vector<int>> arr(201, vector<int>(201,0));

	while (N-- > 0) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;

		x += 100;
		y += 100;
		x1 += 100;
		y1 += 100;

		for (int i = y; i < y1; ++i) {
			for (int k = x; k < x1; ++k) {
				arr[i][k] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 201; ++i) {
		for (int k = 0; k < 201; ++k) {
			if (arr[i][k] == 1) ++cnt;
		}
	}

	cout << cnt;
	return 0;
}