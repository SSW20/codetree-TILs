#include <iostream>
using namespace std;

int pibo(int n){
    if(n == 1) return 1;
    else if(n == 2) return 1;
    return pibo(n-1) + pibo(n-2);
}

int main() {
    // 여기에 코드를 작성해주세요
    int n;
    cin >> n;
    cout << pibo(n);
    return 0;
}