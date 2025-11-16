#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int N;
char grid[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ansMin = INT_MAX;
int pathMin = -1;
int endX, endY;
bool gFlag = false;

pair<int, int> numbers[10];

int Find(int r1, int c1, int r2, int c2)
{
	int maxX = max(r1, r2);
	int maxY = max(c1, c2);

	int minX = min(r1, r2);
	int minY = min(c1, c2);

	return maxX - minX + maxY - minY;
}

void FindPath(int idx, int coin, int coinCount, int total, int r, int c)
{
	if (coinCount >= 3)
	{
		ansMin = min(ansMin, total + Find(numbers[coin].first, numbers[coin].second, endX, endY));
		gFlag = true;
		return;
	}

	for (int i = idx; i < 10; ++i)
	{
		int x = numbers[i].first;
		int y = numbers[i].second;
		if (x != 0 && y != 0)
		{
			FindPath(i + 1, i, coinCount + 1, total + Find(r, c, x, y), x, y);
		}
		FindPath(i + 1, coin, coinCount, total, r, c);
	}
}


int main() {
	int r, c;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'S')
			{
				r = i;
				c = j;
			}
			if (grid[i][j] - '0' <= 9)
			{
				numbers[grid[i][j] - '0'] = (make_pair(i, j));
			}
			if (grid[i][j] == 'E')
			{
				endX = i;
				endY = j;
			}
		}

	// Please write your code here.

	FindPath(1, 0, 0, 0, r, c);

	if (gFlag) cout << ansMin;
	else cout << -1;
	return 0;
}
