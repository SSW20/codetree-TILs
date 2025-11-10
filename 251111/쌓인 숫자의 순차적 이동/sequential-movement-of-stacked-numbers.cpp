#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
int gridMax[20][20];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int main()
{
	cin >> N >> M;

	vector<vector<vector<int>>> grid(N, vector<vector<int>>(N));
	vector<pair<int,int>> numbers(N * N + 1);
	int num;
	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < N; ++k)
		{
			cin >> num;
			grid[i][k].push_back(num);
			gridMax[i][k] = num;
			numbers[num] = make_pair(i, k);
		}
	}



	while (M-- > 0)
	{
		cin >> num;
		int x = numbers[num].first;
		int y = numbers[num].second;

		// 8방향 탐색 
		// 제일 큰 값 찾기 
		int maxX = -1, maxY = -1;
		int max = 0;
		for (int d = 0; d < 8; ++d)
		{
			int tempX = x + dx[d];
			int tempY = y + dy[d];

			if (tempX < 0 || tempY < 0 || tempX >= N || tempY >= N) continue;

			if (gridMax[tempX][tempY] > max)
			{
				max = gridMax[tempX][tempY];
				maxX = tempX;
				maxY = tempY;
			}
		}
		if (maxX == -1 || maxY == -1) continue;

		// 값 바꾸기
		// 그 위치 부터 마지막까지 가져온 뒤 
		// 다음 위치에 삽입
		vector<int> temp;
		auto it = find(grid[x][y].begin(), grid[x][y].end(), num);
		grid[maxX][maxY].insert(grid[maxX][maxY].end(), it, grid[x][y].end());

		// 위치 업데이트
		for (auto iter = it; iter != grid[x][y].end(); ++iter)
		{
			numbers[*iter] = make_pair(maxX, maxY);
		}

		grid[x][y].erase(it, grid[x][y].end());

		if (!grid[x][y].empty())
		{
			auto iter = max_element(grid[x][y].begin(), grid[x][y].end());
			gridMax[x][y] = *iter;
		}
		else gridMax[x][y] = 0;

		if (!grid[maxX][maxY].empty())
		{
			auto iter = max_element(grid[maxX][maxY].begin(), grid[maxX][maxY].end());
			gridMax[maxX][maxY] = *iter;
		}
		else gridMax[maxX][maxY] = 0;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < N; ++k)
		{
			if (grid[i][k].empty()) cout << "None";
			else
			{
				for (int idx = grid[i][k].size()-1; idx > -1; --idx)
				{
					cout << grid[i][k][idx] << ' ';
				}
			}
			cout << '\n';
		}
	}

}