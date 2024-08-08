#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;


int main() {
    
    int n,x;
    cin >> n;

    vector<int> v;
    vector<int> v2;
    for (int i = 1; i < n+1; ++i) {
        cin >> x;
        v.push_back(x);
        v2.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (v[k] == v2[i]) { 
                cout << k + 1 << ' '; 
                v[k] = 0;
                break;
            }

        }
    }

    return 0;
}