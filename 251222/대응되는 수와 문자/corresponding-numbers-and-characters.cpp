#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    
    unordered_map<string, string> umap;

    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        umap[to_string(i)] = s;
        umap[s] = to_string(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> s;
        if (umap.find(s) != umap.end())
        {
            cout << umap[s] << '\n';
        }
    }


    return 0;
}