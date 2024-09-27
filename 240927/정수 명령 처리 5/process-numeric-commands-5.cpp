#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N,x;
	vector<int> v;
	string s;
	cin >> N;
	while (N-- > 0) {
		cin >> s;
		if (s == "push_back")
		{
			cin >> x;
			v.push_back(x);
		}
		else if (s == "pop_back")
		{
			v.pop_back();
		}
		else if (s == "size")
		{
			cout << v.size() << '\n';
		}
		else {
			cin >> x;
			cout << v[x - 1] << '\n';
		}
	}
}