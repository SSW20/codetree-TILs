#include <iostream>
using namespace std;


void descending(int n){
    if(n == 0) return;
    cout << n << ' ';
    descending(n-1);
}

void ascending(int n){
    if(n == 0) return;
    ascending(n-1);
    cout << n << ' ';
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    ascending(n);
    cout << '\n';
    descending(n);

    return 0;
}