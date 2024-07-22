#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,total=0;
    cin >> n;
    for(int i=1; i<=n; ++i) total += i;
    cout << total / 10;
    return 0;
}