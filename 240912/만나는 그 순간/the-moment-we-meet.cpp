#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	vector<int> v(1000001,0);
	vector<int> v2(1000001,0);

	char c;
	int t;


	int idx = 1;
	while (n-- > 0) {
		cin >> c >> t;
		while (t-- > 0) {
			if (c == 'R') {
				v[idx] = v[idx - 1]+  1;
			}
			else {
				v[idx] = v[idx - 1]- 1;
			}
			idx++;
		}
	}
	idx = 1;
	while (m-- > 0) {
		cin >> c >> t;
		while (t-- > 0) {
			if (c == 'R') {
				v2[idx] = v2[idx-1]+ 1;
			}
			else {
				v2[idx] = v2[idx-1]- 1;
			}
			idx++;
		}
	}

	int ans = -1;
	for (int i = 1; i < idx; ++i) {
		if (v[i] == v2[i]) { ans = i;  break; }
	}

	cout << ans;
	return 0;
}