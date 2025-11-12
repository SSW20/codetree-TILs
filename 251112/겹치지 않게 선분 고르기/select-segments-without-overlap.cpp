#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int maxCount = 1;
void Calculate(int idx, int count, int end)
{
    if (idx == v.size())
    {
        maxCount = max(maxCount, count);
        return;
    }

    int left = v[idx].first;
    int right = v[idx].second;
    if (end >= left)
    {
        Calculate(idx + 1, count, end);
    }
    else {
        Calculate(idx + 1, count + 1, right);
    }
}
int main() {
    cin >> n;
    int x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        Calculate(i, 0, -1);
    }
    cout << maxCount;

    // Please write your code here.

    return 0;
}
