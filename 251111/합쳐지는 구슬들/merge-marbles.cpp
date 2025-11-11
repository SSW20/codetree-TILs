#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, T;
int r, c,  w;
char d;
int asci[128];


// r c w 번호 d
using Tuple = tuple<int, int, int,int, int>;

// w 번호  d
vector<tuple<int, int, int>> grid[50][50];
int main()
{
	cin >> N >> M >> T;

	asci['U'] = 0;
	asci['R'] = 1;
	asci['D'] = 2;
	asci['L'] = 3;

	vector<Tuple> numbers(M);

	for(int i=0; i<M;++i)
	{
		cin >> r >> c >> d >> w;
		numbers[i] = { r - 1,c - 1,w,i+1,asci[d] };
		grid[r - 1][c - 1].push_back({ w,i + 1,asci[d] });
	}

	while (T-- > 0)
	{
		for (int i = 0; i < numbers.size(); ++i)
		{
			int x, y, w, d, num;
			tie(x, y, w, num, d) = numbers[i];
			int dx[4] = { -1,0,1,0 };
			int dy[4] = { 0,1,0,-1 };
			grid[x][y].pop_back();

			if (x + dx[d] < 0 || x + dx[d] >= N || y + dy[d] < 0 || y + dy[d] >= N) { d = (d + 2) % 4; }
			else {x += dx[d]; y += dy[d];}

			
			if(grid[x][y].empty()) { grid[x][y].push_back({ w,num,d });}
			else
			{
				int preW, preNum, preD;
				tie(preW, preNum, preD) = grid[x][y].front();

				if (num < preNum)
				{
					num = preNum;
					d = preD;
				}

				grid[x][y].pop_back();
				grid[x][y].push_back({ w + preW, num, d });
			}
		}
		numbers.clear();
		for (int i = 0; i < N; ++i)
		{
			for (int k = 0; k < N; ++k)
			{
				if (grid[i][k].size() > 0)
				{
					int w, d, num;
					tie(w, num, d) = grid[i][k].front();
					numbers.push_back({ i,k,w,num,d });
				}
			}
		}

	}

	int count = numbers.size();
	int maxWeight = -1;

	for (int i = 0; i < numbers.size(); ++i)
	{
		int x, y, w, d, num;
		tie(x, y, w, num, d) = numbers[i];
		if (maxWeight < w) maxWeight = w;
	}

	cout << count << ' ' << maxWeight;
}