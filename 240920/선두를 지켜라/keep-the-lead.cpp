#include <iostream>
#include <vector>
using namespace std;

int main() {
	int v, t, n, m;
	vector<int> a(1000001,0);
	vector<int> b(1000001,0);
	cin >> n >> m;
	int idx = 1;
	while (n-- > 0) {
		cin >> v >> t;
		while (t-- > 0) {
			a[idx] = a[idx - 1] + v;
			idx++;
		}
	}

	idx = 1;
	while (m-- > 0) {
		cin >> v >> t;
		while (t-- > 0) {
			b[idx] = b[idx - 1] + v;
			idx++;
		}
	}

	int cnt = 0;
	char c = ' ';
	for (int i = 1; i <= 1000000; ++i) {
		if (a[i] < b[i]  && (c == ' ' || c == 'a')) { c = 'b'; ++cnt; }
		else if (a[i] > b[i] && (c == ' ' || c == 'b'))  { c = 'a'; ++cnt; }
	}

	std::cout << cnt-1;
	return 0;
}