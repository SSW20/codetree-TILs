#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int n;
unordered_map<int,int> umap;

int main() {
    cin >> n;
  
    int x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;

        if (umap.find(x) != umap.end())
        {
            if (umap[x] > y)
            {
                umap[x] = y;
            }
        }
        else umap[x] = y;
    }

    long long int total = 0;

    for (auto it = umap.begin(); it != umap.end(); ++it)
    {
        total += it->second;
    }
    cout << total;
    return 0;
}
