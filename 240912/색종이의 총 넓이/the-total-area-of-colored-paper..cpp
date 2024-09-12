#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> v(101, vector<int>(101));
	while (N-- > 0) {
		int x, y;
		cin >> x >> y;

		for (int i = y; i < y + 8; ++i) {
			for (int k = x; k < x + 8; ++k) {
				v[i][k] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 101; ++i) {
		for (int k = 0; k < 101; ++k) {
			if (v[i][k] == 1) ++cnt;
		}
	}
	
	cout << cnt;
	return 0;
}