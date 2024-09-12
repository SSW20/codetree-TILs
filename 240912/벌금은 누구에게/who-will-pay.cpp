#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int n, k, m,x;
	cin >> n >> m >> k;

	vector<int> st(n + 1,0);
	while (m-- > 0) {
		cin >> x;
		st[x]++;

		if (st[x] == k) {
			cout << x;
			return 0;
		}
	}

	cout << -1;

	return 0;
}