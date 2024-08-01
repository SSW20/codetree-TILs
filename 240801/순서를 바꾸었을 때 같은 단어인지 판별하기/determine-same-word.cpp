#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
   string s,s2;
   cin >> s  >> s2;
   sort(s.begin(), s.end());
   sort(s2.begin(), s2.end());

   if(s.length() != s2.length()) {
    cout << "No";
    return 0;
   }

   for(int i=0;i<s.length(); ++i){
    if(s[i] != s2[i]) {
        cout << "No";
    return 0;
    }
   }

    cout << "Yes";

    return 0;
}