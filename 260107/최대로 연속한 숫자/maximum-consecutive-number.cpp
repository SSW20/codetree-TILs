#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, m, x;
set<int> s;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x;
        s.insert(x);
        int ans = 0;

        auto it = s.begin();
        ans = max(ans, *it);
        while (it != s.end())
        {
            auto nxt = next(it);
            if (nxt == s.end())
            {
                ans = max(ans, n - *it);
                break;
            }
            ans = max(ans, *nxt - *it - 1);
            it++;
        }

        cout << ans << '\n';
    }




    /* auto it = s.begin();
     int ans = *it;
     it++;

     while (it != --s.end())
     {
         auto nxt = next(it);
         ans = max(ans, *nxt - *it);
         it++;
     }*/

    return 0;
}
