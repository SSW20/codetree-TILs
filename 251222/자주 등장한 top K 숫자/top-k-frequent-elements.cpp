#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int arr[100000];
unordered_map<int, int> umap;
vector<pair<int, int>> v;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        umap[arr[i]]++;
    }

    for (auto it = umap.begin(); it != umap.end(); ++it) {
        v.push_back({ it->second, it->first });
    }
    sort(v.begin(), v.end());

    for (int i = (int)v.size() - 1; i >= (int)v.size() - k; i--)
        cout << v[i].second << " ";
   
    return 0;
}
