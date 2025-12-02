#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int startVal, endVal;
vector<pair<int, int>> v;
int dp[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> startVal >> endVal;
        v.push_back({ endVal, startVal });
    }

        
    sort(v.begin(), v.end());

    int curStart = 0;
    int curEnd = -1;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int end = v[i].first;
        int start = v[i].second;
        if (start > curEnd)
        {
            curStart = start;
            curEnd = end;
            ++count;
        }
    }

    cout << count;
    return 0;
}
