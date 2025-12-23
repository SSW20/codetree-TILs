#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int n;
string words[1000];
unordered_map<string,int> umap;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        sort(words[i].begin(), words[i].end());
        umap[words[i]]++;
    }

    int ansmax = -1;
    for (auto it = umap.begin(); it != umap.end(); ++it)
    {
        ansmax = max(ansmax, it->second);
    }
    
    cout << ansmax;

    return 0;
}
