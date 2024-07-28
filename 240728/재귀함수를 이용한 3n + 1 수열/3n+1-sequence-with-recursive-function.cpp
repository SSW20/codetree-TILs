#include <iostream>
using namespace std;

int count = 0;

int sequence(int n){
    if(n == 1) return count;
    ++count;
    if(n % 2 == 0) return sequence(n / 2);
    else return sequence(n * 3 + 1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    sequence(n);
    cout << count;

    return 0;
}