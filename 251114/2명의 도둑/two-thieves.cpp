#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, C;
int ansMax = -1;
int weightMax;

int v[10][10];
int selected[10];

void FindMaxWeight(int curW, int curCount, int total)
{
	if (curCount == M)
	{
		if (curW <= C)
		{
			weightMax = max(total, weightMax);
		}
		return;
	}
	FindMaxWeight(curW, curCount + 1, total);
	FindMaxWeight(curW + selected[curCount], curCount + 1, total + selected[curCount] * selected[curCount]);
}

int FindMax(int x, int y)
{
	for (int i = 0; i < M; ++i)
	{
		selected[i] = v[x][i + y];
	}

	weightMax = 0;
	FindMaxWeight(0, 0, 0);
	return weightMax;

}

bool Possible(int x1, int y1, int x2, int y2)
{
	if (y1 + M - 1 >= N || y2 + M - 1 >= N) return false;
	if (x1 != x2) return true;
	if (y1 + M - 1 >= y2 || y2 + M - 1 <= y1) return false;
	return true;
}

int main()
{
	cin >> N >> M >> C;
	int x;
	for (int i = 0; i < N; ++i)
		for (int k = 0; k < N; ++k)
		{
			cin >> v[i][k];
		}

	for (int i = 0; i < N; ++i)
		for (int k = 0; k < N; ++k)
			for(int x = 0; x< N; ++x)
				for (int y = 0; y < N; ++y)
				{
					if (Possible(i, k, x, y))
					{
						ansMax = max(ansMax, FindMax(i, k)
							+ FindMax(x, y));
					}
				}
	cout << ansMax;
}
