#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt = 1;
	int max = 0;
	int x, cur;
	int n;

	cin >> n;
	cin >> x;
	cur = x;
	n--;
	
	if (n == 0) { cout << 1; return 0; }

	while (n-- > 0) {
		cin >> x;
		if (cur == x) ++cnt;
		else { if (max < cnt) { max = cnt; cnt = 1; } }
		cur = x;
	}
	cout << max;
}