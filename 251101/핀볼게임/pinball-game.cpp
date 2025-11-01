#include <iostream>

using namespace std;

int n;
int grid[100][100];

int calculate(int r, int c, char d)
{
	int x = r;
	int y = c;
	int count = 1;
	while (true)
	{
		if (x < 0 || y < 0 || x >= n || y >= n) break;
		if (grid[x][y] == 1) {
			if (d == 'U')  d = 'R';
			else if (d == 'R')  d = 'U';
			else if (d == 'D')  d = 'L';
			else d = 'D';
		}
		if (grid[x][y] == 2) {
			if (d == 'U')  d = 'L';
			else if (d == 'R')  d = 'D';
			else if (d == 'D')  d = 'R';
			else d = 'U';
		}

		if (d == 'U')
		{
			x--;
		}
		else if (d == 'L')
		{
			y--;
		}
		else if (d == 'R')
		{
			y++;
		}
		else
		{
			x++;
		}
		++count;
	}
	return count;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> grid[i][j];
	int ans = -1;

	// Please write your code here.
	for (int j = 0; j < n; j++)
	{
		int temp = calculate(0, j, 'D');
		ans = max(ans, temp);
	}

	for (int j = 0; j < n; j++)
	{
		int temp = calculate(j, n - 1, 'L');
		ans = max(ans, temp);
	}
	for (int j = 0; j < n; j++)
	{
		int temp = calculate(j, 0, 'R');
		ans = max(ans, temp);
	}
	for (int j = 0; j < n; j++)
	{
		int temp = calculate(n - 1, j, 'U');
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}
