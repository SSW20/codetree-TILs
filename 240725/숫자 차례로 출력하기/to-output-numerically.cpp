#include <iostream>
using namespace std;

int temp = 1;

void descending(int n){
    if(n == 0) return;
    cout << n << ' ';
    return descending(n-1);
}

void ascending(int n){
    if(n < temp) return;
    cout << temp << ' ';
    temp++;
    return ascending(n);
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