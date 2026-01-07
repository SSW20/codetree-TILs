#include <iostream>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
int arr[100000];

int ans = INT_MAX;
set<int> s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    // Please write your code here.
    for (int i = 0; i < n; i++)
    {

        if (s.lower_bound(arr[i] + m) != s.end())
        {
            ans = min(ans, *s.lower_bound(arr[i] + m) - arr[i]);
        }

        if (s.upper_bound(arr[i] - m) != s.begin())
        {
            ans = min(ans, arr[i] - *(s.upper_bound(-arr[i] + m)--));
        }
    }
        
    if (ans == INT_MAX)
        ans = -1;

    cout << ans;

    return 0;
}
