#include <iostream>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

int n, m,x,y,k;
int arr[100000];
set<pair<int,int>> s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        s.insert({x,y});
    }
    // Please write your code here.
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        if (s.lower_bound({ k,0 }) != s.end())
        {
            cout << (*s.lower_bound({ k,0 })).first << ' ' << (*s.lower_bound({ k,0 })).second;
            s.erase(s.lower_bound({ k,0 }));
        }
        else
        {
            cout << -1 << ' ' << -1;
        }
        cout << '\n';
    }
        
  


    return 0;
}
