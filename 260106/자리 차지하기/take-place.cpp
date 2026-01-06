#include <iostream>
#include <set>
using namespace std;

int n, m;
int a[100000];
set<int> s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        s.insert(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num = a[i];

        auto it = s.upper_bound(num);

        if (it == s.begin()) break;

        --it;
        s.erase(it);
        ans++;
    }

    cout << ans;

    return 0;
}
