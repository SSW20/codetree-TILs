#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	stack<int> st;
	cin >> n;

	if (n == 1 || n == 0) { cout << n; return 0; }
	while (n != 0) {
		st.push(n % 2);
		n = n / 2;
	}


	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	
	return 0;
}