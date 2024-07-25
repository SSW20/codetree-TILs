#include <iostream>
using namespace std;

int findIndex(string s, string s2){
    bool flag = false;
    for(int i=0;i<s.length(); ++i){
        if(s[i] == s2[0]){
            flag = true;
            for(int k=0;k<s2.length(); ++k){
                if(s[i+k] != s2[k]) flag = false;
            }
            if(flag) return i;
        }
    }
    return -1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    string s,s2;
    cin >> s >> s2;

    cout << findIndex(s,s2);
    return 0;
}