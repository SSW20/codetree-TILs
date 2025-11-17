#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int>> lines;
int ansMin = INT_MAX;
int Cal(int min, int max)
{
    int x = lines[max].first - lines[min].first;
    int y = lines[max].second - lines[min].second;
    return x * x + y * y;
}

void Select(int idx, int cnt, int minId,  int maxId)
{
    if (cnt == m)
    {
        ansMin = min(ansMin, Cal(minId, maxId));
        return;
    }
    for (int i = idx; i < lines.size(); ++i)
    {
        if (cnt == 0) minId = i;
        if (cnt == m - 1) maxId = i;
        Select(i + 1, cnt + 1, minId, maxId);
    }
}

int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        lines.push_back(make_pair(x, y));
    }
    sort(lines.begin(), lines.end());

    Select(0, 0, -1, -1);
    cout << ansMin;

    // Please write your code here.

    return 0;
}
