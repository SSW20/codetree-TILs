#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int n;
string word;
unordered_map<char,int> umap;

int main() {
    cin >> word;
  
    for (char c : word)
    {
        umap[c]++;
    }

    char c = 'A';
    for (auto it = umap.begin(); it != umap.end(); ++it)
    {
        if (it->second == 1)
        {
            c =  it->first;
            break;
        }
    }
    
    if (c == 'A')
    {
        cout << "None";
    }
    else cout << c;
    return 0;
}
