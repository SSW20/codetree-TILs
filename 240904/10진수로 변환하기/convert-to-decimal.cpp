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

	cout << n;
	return 0;
}