#include <iostream>
using namespace std;

int count(int n){
    if(n == 1) return 0;
    else if(n % 2 == 0) return 1 + count(n/2);
    else return 1 + count(n/3);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    cout << count(n);
    return 0;
}