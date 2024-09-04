#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	stack<int> st;

	while (n != 0) {
		st.push(n % k);
		n /= k;
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	
	return 0;
}