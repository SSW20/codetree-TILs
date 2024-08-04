#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,x;
    cin >> n;
    vector<int> v;
    
    for(int i=0;i<n;++i) {
        cin >> x;
        v.push_back(x); 
        sort(v.begin(), v.end());
        if(i%2 == 0){
                cout << v[i/2] << ' ';
        }
    }
   
    return 0;
}