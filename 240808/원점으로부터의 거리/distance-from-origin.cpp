#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;


static bool comp(tuple<int,int,int> a, tuple<int, int, int> b) {
    if (abs(get<0>(a)) + abs(get<1>(a) == abs(get<0>(b)) + abs(get<1>(b)))) return get<2>(a) < get<2>(b);
    return (abs(get<0>(a)) + abs(get<1>(a)) < (abs(get<0>(b)) + abs(get<1>(b))));
}

int main() {
    vector<tuple<int, int, int>> v;
    int x, y, n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back(make_tuple(x, y, i+1));
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < n; ++i) {
        cout << get<2>(v[i])  << '\n';
    }

    return 0;
}