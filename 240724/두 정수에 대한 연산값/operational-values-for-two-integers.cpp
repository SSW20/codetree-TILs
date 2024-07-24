#include <iostream>
using namespace std;

void matrix(int &a, int &b){
    a = a * 2;
    b = b + 25;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b;
    cin >> a >> b;
    if(a > b) matrix(b,a);
    else matrix(a,b);
    cout << a << ' '<<  b;
    return 0;
}