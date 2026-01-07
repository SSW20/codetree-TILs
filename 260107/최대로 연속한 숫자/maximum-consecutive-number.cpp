#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<pair<int, int>> range;
    multiset<int> length;

    range.insert({ 0,n });
    length.insert(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;

        auto it = range.upper_bound({ x,x });
        it--;

        int start = it->first;
        int end = it->second;
        int len = end - start + 1;

        length.erase(length.find(len));
        range.erase(it);

        range.insert({ start, x-1 });
        range.insert({ x + 1, end });

        length.insert(x - start);
        length.insert(end - x);

       
        cout << *length.rbegin() << "\n";
    }

    return 0;
}