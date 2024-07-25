#include <iostream>
using namespace std;

int sqr(int n){
    if(n == 0) return 0;
    return (n % 10) * (n % 10) + sqr(n/10);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    cout << sqr(n);
    return 0;
}