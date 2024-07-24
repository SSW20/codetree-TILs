#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){
    for(int i=0; i<s.length() / 2; ++i){
        if(s[i] != s[s.length() - i - 1]) return false;
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    string s;
    cin >> s;
    if(isPalindrome(s)) cout << "Yes";
    else cout << "No";
    return 0;
}