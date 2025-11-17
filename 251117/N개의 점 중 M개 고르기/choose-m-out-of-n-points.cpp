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
    sort(selectLines.begin(), selectLines.end());

    int x = selectLines[0].first - selectLines[length - 1].first;
    int y = selectLines[0].second - selectLines[length - 1].second;
    int maxVal = pow(x, 2) + pow(y, 2);

    for (int i = 1; i < length - 1; ++i)
    {
        int tempX = selectLines[i].first - selectLines[length - 1].first;
        int tempY = selectLines[i].second - selectLines[length - 1].second;
        int temp = pow(tempX, 2) + pow(tempY, 2);
        if (temp > maxVal)
        {
            maxVal = temp;
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
        Select(i +  1, cnt + 1);
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
    sort(lines.begin(), lines.end());

    Select(0, 0);
    cout << ansMin;

    // Please write your code here.

    return 0;
}
