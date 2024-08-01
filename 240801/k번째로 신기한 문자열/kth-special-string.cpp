#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k;
    string s,T;
    cin >> n >> k >> T;

    vector<string> v;
    while(n-->0){
        cin >> s;
        bool flag = true;
        for(int i=0; i<T.length(); ++i){
            if(T[i] != s[i]) flag = false;
        }

        if(flag) v.push_back(s);
    }
    

    sort(v.begin(),v.end());
    cout << v[k-1];



    return 0;
}