#include <iostream>
using namespace std;

bool isOdd(int a){
    int cnt = 0;
    while(a > 0){
        cnt += a % 10;
        a /=10;
    }
    if(cnt % 2 == 0) return true;
    return false;
}
bool isPrime(int a){
    for(int i=2; i<a; ++i){
        if(a % i == 0) return false;
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a,b,cnt=0;
    cin >> a >> b;
    for(int i=a; i<=b; ++i){
        if(i == 1) continue;
        if(isOdd(i) && isPrime(i)) ++cnt;
    }
    cout << cnt;
    return 0;
}