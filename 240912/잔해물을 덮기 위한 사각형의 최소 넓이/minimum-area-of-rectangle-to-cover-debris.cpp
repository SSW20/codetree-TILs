#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<vector<int>> v(2010, vector<int>(2010));
	int N = 2;
	int flag = true;
	while (N-- > 0) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;

		x += 1000;
		y += 1000;
		y1 += 1000;
		x1 += 1000;

		for (int i = y; i < y1; ++i) {
			for (int k = x; k < x1; ++k) {
				if (flag) v[i][k] = 1;
				else v[i][k] = 0;
			}
		}

		flag = false;
	}

	flag = false;
	int maxX = 0, maxY = 0, minX = 2000, minY = 2000;
	for (int i = 0; i <= 2000; ++i) {
		for (int k = 0; k <= 2000; ++k) {
			{
				if (v[i][k] == 1) {
					flag = true;
					if (maxX < k) maxX = k;
					if (minX > k) minX = k;
					if (maxY < i) maxY = i;
					if (minY > i) minY = i;
				}

			}
		}
	}
	if (!flag) cout << 0;
	else cout << (maxX - minX + 1) * (maxY - minY + 1);

	return 0;
}