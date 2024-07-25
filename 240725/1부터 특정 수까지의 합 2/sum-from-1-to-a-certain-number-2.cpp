#include <iostream>
using namespace std;

int total(int n){
    if(n == 0) return 0;
    return n + total(n-1);
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;
    cout << total(n);
    return 0;
}