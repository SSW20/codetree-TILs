#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	string s;
	cin >> s;


	for (int i=0;i<s.size(); ++i){
		n += (s[i] - '0') * pow(2, s.size() - 1 - i);
	}

	n *= 17;

	stack<int> st;
	while (n != 0) {
		st.push(n % 2);
		n /= 2;
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}