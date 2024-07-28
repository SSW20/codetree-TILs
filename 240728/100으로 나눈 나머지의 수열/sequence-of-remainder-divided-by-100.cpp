#include <iostream>
using namespace std;

int recursive(int n){
    if(n == 1) return 2;
    else if(n == 2) return 4;
    return recursive(n-1) * recursive(n-2) % 100; 
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    cout << recursive(n);
    return 0;
}