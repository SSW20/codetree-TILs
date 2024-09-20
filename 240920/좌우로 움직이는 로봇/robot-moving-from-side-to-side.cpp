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

	idx = 1;
	while (m-- > 0) {
		cin >> t >> c;
		while (t-- > 0) {
			if (c == 'L') {
				b[idx] = b[idx - 1] - 1;
			}
			else {
				b[idx] = b[idx - 1] + 1;
			}
			idx++;
		}
	}

	int cnt = 0;
	for (int i = 1; i < idx; ++i) {
		if (a[i] != b[i] && a[i + 1] == b[i + 1]) ++cnt;
	}

	std::cout << cnt;
	return 0;
}