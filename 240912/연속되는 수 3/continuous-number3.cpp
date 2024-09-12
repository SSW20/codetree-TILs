#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; ++i) cin >> v[i];

	int cnt = 1;
	int max = 1;
	for (int i = 0; i < n-1; ++i) {
		if ((v[i] > 0 && v[i+1] > 0) || (v[i] < 0 && v[i+1] < 0)) ++cnt;
		else {
			cnt = 1;
		}
		if (max < cnt) max = cnt;
 	}
	
	cout << max;
	return 0;
}