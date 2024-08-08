#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int a, b, c;
    cin >> a >> b >> c;
    int total = 24 * 60 * (a - 11) + 60 * (b - 11) + c - 11;
    if (total < 0) cout << -1;
    else cout << total;
    return 0;
}