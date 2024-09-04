#include <iostream>
using namespace std;

int arr[101];

int main() {
	int n, k,a,b;
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> a >> b;
		for (int j = a; j <= b; ++j) arr[j] += 1;
	}

	int max = -1;
	for (int i = 1; i <= n; ++i) {
		if (max < arr[i]) max = arr[i];
	}

	cout << max;
	return 0;
}