#include <iostream>
using namespace std;

int arr[101];

int main() {
	int n;
	cin >> n;
	int a, b;
	while (n-- > 0) {
		cin >> a >> b;
		for (int i = a; i <= b; ++i) arr[i] += 1;
	}

	int max = -1;
	for (int i = 0; i <= 101; ++i) {
		if (max < arr[i]) max = arr[i];
	}

	cout << max;
	return 0;
}