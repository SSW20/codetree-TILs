#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int n, m;
vector<pair<int, int>> lines;
vector<pair<int, int>> selectLines;

int ansMin = INT_MAX;
int Cal()
{
    int length = selectLines.size();
    int maxVal = -1;

    for (int i = 0; i < length; ++i)
    {
        for (int k = i + 1; k < length; ++k)
        {
            int x = selectLines[i].first - selectLines[k].first;
            int y = selectLines[i].second - selectLines[k].second;
            int temp = x * x + y * y;
            if (maxVal < temp) maxVal = temp;
        }
    }
    return maxVal;
}

void Select(int idx, int cnt)
{
    if (cnt == m)
    {
        ansMin = min(ansMin, Cal());
        return;
    }
    for (int i = idx; i < lines.size(); ++i)
    {
        selectLines.push_back(lines[i]);
        Select(i + 1, cnt + 1);
        selectLines.pop_back();
    }
}

int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        lines.push_back(make_pair(x, y));
    }

    Select(0, 0);
    cout << ansMin;

    // Please write your code here.

    return 0;
}
