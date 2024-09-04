#include <iostream>
using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;
	int a;
	char c;
	int loc = 500;
	while (n-- > 0) {
		cin >> a >> c;
		if (c == 'R') {
			for (int i = loc; i < a + loc; ++i) arr[i] += 1;
			loc = loc + a;
		}
		else {
			for (int i = loc; i > loc - a; --i) arr[i] += 1;
			loc = loc - a;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 1000; ++i) {
		if (arr[i] > 1) cnt +=1;
	}

	cout << cnt;
	return 0;
}