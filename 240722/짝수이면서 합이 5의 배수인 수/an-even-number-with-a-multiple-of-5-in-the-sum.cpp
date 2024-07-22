#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x,y,n;
    cin >> n;
    x = n / 10;
    y = n % 10;
    if((x + y) % 5 == 0 && n % 2 == 0) cout << "Yes";
    else cout << "No";
    return 0;
}