#include <iostream>
#include<vector>
using namespace std;

vector<int> numbers;
int visited[10];
int N;

void Calc(int cnt)
{
	if (cnt == N)
	{
		for (int x : numbers) cout << x << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (visited[i] >= 1) continue;

		numbers.push_back(i);
		visited[i] = 1;
		Calc(cnt + 1);
		numbers.pop_back();
		visited[i] = 0;
	}
}


int main()
{
	cin >> N;
    Calc(0);
}