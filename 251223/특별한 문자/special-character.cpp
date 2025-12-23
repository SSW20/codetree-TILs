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

    char ans = 'A';
    for (char c : word)
    {
        if (umap[c] == 1)
        {
            ans = c;
            break;
       }
    }
    
    if (ans == 'A')
    {
        cout << "None";
    }
    else cout << ans;
    return 0;
}
