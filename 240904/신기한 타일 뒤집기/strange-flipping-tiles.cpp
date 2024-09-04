#include <iostream>
using namespace std;

int arr[200001];
int b[200001];
int w[200001];
int main() {
	int n;
	cin >> n;
	int a;
	char c;
	int loc = 100000;
	while (n-- > 0) {
		cin >> a >> c;
		if (c == 'R') {
			while (a--) {
				b[loc] += 1;
				arr[loc] = 1;
				if (a) loc++;
			}
		}
		else {
			while (a--) {
				w[loc] += 1;
				arr[loc] = 2;
				if(a) loc--;
			}
		}
	}

	int b_cnt = 0, w_cnt = 0, g_cnt = 0;
	for (int i = 0; i <= 200001; ++i) {
		if (arr[i] == 1) ++b_cnt;
		else if (arr[i] == 2) ++w_cnt;
	}

	cout << w_cnt << ' ' << b_cnt;
	return 0;
}