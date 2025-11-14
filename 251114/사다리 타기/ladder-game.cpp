#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<pair<int, int>> lines;
vector<pair<int, int>> selectedLines;
int ans = INT_MAX;

bool Possible()
{
	int line[11];
	int changedLine[11];

	for (int i = 0; i < N; ++i)
	{
		line[i] = changedLine[i] = i;
	}

	for (int i = 0; i < lines.size(); ++i)
	{
		int idx = lines[i].second;
		swap(line[idx], line[idx + 1]);
	}

	for (int i = 0; i < selectedLines.size(); ++i)
	{
		int idx = selectedLines[i].second;
		swap(changedLine[idx], changedLine[idx + 1]);
	}

	for (int i = 0; i < N; ++i)
	{
		if (line[i] != changedLine[i]) return false;
	}
	return true;
}

void FindMinLines(int count)
{
	if (count == M)
	{
		if (Possible())
		{
			ans = min(ans, int(selectedLines.size()));
		}
		return;
	}
	
	selectedLines.push_back(lines[count]);
	FindMinLines(count + 1);

	selectedLines.pop_back();

	FindMinLines(count + 1);
}

int main()
{
	cin >> N >> M;
	for(int i=0; i<M; ++i)
	{
		int x, y;
		cin >> x >> y;
		lines.push_back(make_pair(y, x-1));
	}
	sort(lines.begin(), lines.end());

	FindMinLines(0);

	cout << ans;
}