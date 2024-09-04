#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;


	for (int i=0;i<s.size(); ++i){
		n += (s[i] - '0') * pow(a, s.size() - 1 - i);
	}


	stack<int> st;
	while (n != 0) {
		st.push(n % b);
		n /= b;
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}