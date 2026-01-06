#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int arr[100000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        for (int k = i + 1; k < n; ++k)
        {
            s.insert(abs(arr[i] - arr[k]));
        }
    }

    auto it = s.lower_bound(m);

    if (it == s.end()) cout << -1;
    else cout << *it;
    return 0;
}
