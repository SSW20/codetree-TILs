#include <iostream>

using namespace std;

int N;
unsigned long long int f[1001];
unsigned long long int Fibo(int n)
{
    if (f[n] != 0) return f[n];

    if (n <= 1)
    {
        f[n] = 1;
    }
    else
    {
        f[n] = (Fibo(n - 1) % 10007 + Fibo(n - 2) % 10007) % 10007;
    }
    return f[n];
}
int main() {
    cin >> N;

    // Please write your code here.
    cout << Fibo(N);
    return 0;
}