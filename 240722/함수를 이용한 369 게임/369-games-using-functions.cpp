#include <iostream>
#include <string>
using namespace std;

bool isValid(int a){
    string s = to_string(a);
    for(char c : s){
        if(c == '3' || c == '6' || c == '9') return true;
    }
    if(a % 3 == 0) return true;
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int a,b,count = 0;
    cin >> a >> b;
    for(int i=a; i<=b;++i){
        if(isValid(i)) ++count;
    }
    cout << count;
    return 0;
}