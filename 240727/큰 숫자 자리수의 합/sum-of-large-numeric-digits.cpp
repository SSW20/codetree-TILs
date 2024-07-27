#include <iostream>
using namespace std;

int total(int a){
    if(a == 0) return 0;
    return a%10 + total(a/10);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,c;
    cin >> a >> b >> c;
    cout << total(a*b*c);
    return 0;
}