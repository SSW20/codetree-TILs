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
	
	while (n-- > 0) {
		cin >> x;
		if (cur == x) ++cnt;
		else { if (max < cnt) { max = cnt; cnt = 1; } }
		cur = x;
	}

	if (max < cnt) max = cnt;
	cout << max;
}