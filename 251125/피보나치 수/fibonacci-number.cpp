#include <iostream>

using namespace std;

int N;
int f[46];
int Fibo(int n)
{
    if(f[n] != 0) return f[n];

    if(n <=2)
        f[n] = 1;
    else
        f[n] = Fibo(n-1) + Fibo(n-2);
        
    return f[n];
}

int main() {
    cin >> N;

    // Please write your code here.
    cout << Fibo(N);
    return 0;
}
