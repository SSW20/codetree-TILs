#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n, m;
	char c;
	vector<int> a(1000001,0);
	vector<int> b(1000001,0);
	cin >> n >> m;
	int idx = 1;
	while (n-- > 0) {
		cin >> t >> c;
		while (t-- > 0) {
			if (c == 'L') {
				a[idx] = a[idx - 1] -1;
			}
			else {
				a[idx] = a[idx - 1] + 1;
			}
			idx++;
		}
	}

	for (; idx < 1000001; ++idx) { a[idx] = a[idx - 1]; }

	int idx2 = 1;
	while (m-- > 0) {
		cin >> t >> c;
		while (t-- > 0) {
			if (c == 'L') {
				b[idx2] = b[idx2 - 1] - 1;
			}
			else {
				b[idx2] = b[idx2- 1] + 1;
			}
			idx2++;
		}
	}
	for (; idx2 < 1000001; ++idx2) { b[idx2] = b[idx2 - 1]; }

	int cnt = 0;
	for (int i = 1; i < 1000000; ++i) {
		if (a[i] != b[i] && a[i + 1] == b[i + 1]) ++cnt;
	}

	std::cout << cnt;
	return 0;
}