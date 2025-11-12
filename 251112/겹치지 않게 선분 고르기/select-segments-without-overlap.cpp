#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
int maxCount = 1;
void Calculate(int idx, int count, int end)
{
    if (idx >= v.size())
    {
        if (count > maxCount) maxCount = count;
        return;
    }
    
    int left = v[idx].first;
    int right = v[idx].second;
    if (end >= left)
    {
        if (count > maxCount) maxCount = count;
        return;
    }

    for (int i = idx; i < v.size(); ++i)
    {
        end = v[idx].second;
        for (int k = idx + 1; k < v.size(); ++k)
        {
            Calculate(idx + k, count + 1, right);
        }
    }
}
int main() {
    cin >> n;
    int x, y;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    Calculate(0, 1, -1);
    cout << maxCount;

    // Please write your code here.

    return 0;
}
