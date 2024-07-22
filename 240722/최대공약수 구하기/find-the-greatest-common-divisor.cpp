#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin >> n >> m;
    if(m > n) {
        int tmp = n;
        n = m;
        m = tmp;
    }

    int r = n % m;
    while(r != 0){
        if(m < r) break;
        int tmp = r;
        r = m % r;
        m = tmp;
    }
    if(r != 0) cout << 1;
    else cout << m;
    return 0;
}