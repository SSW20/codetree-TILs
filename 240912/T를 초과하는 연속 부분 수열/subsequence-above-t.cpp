#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,t;
	cin >> n >> t;
	vector<int> v(n);

	for (int i = 0; i < n; ++i) cin >> v[i];

	int cnt = 1;
	int max = 1;
	for (int i = 0; i < n-1; ++i) {
		if (v[i] > t && v[i+1] > t) ++cnt;
		else {
			cnt = 1;
		}
		if (max < cnt) max = cnt;
 	}
	
	cout << max;
	return 0;
}