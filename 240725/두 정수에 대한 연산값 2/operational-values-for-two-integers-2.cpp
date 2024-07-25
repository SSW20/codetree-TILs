#include <iostream>
using namespace std;

void calculate(int &a, int &b){
    a += 10;
    b *= 2;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b;
    cin >> a >> b;
    if(a > b) calculate(b,a);
    else calculate(a,b);
    cout << a << ' ' << b;
    return 0;
}