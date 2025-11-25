#include <iostream>

using namespace std;

int N;
long long int f[1001];
long long int Fibo(int n)
{
    if (f[n] != 0) return f[n];

    if (n <= 4)
    {
        f[n] = 1;
    }
    else
    {
        f[n] = Fibo(n - 2) + Fibo(n - 3);
    }
    return f[n];
}
int main() {
    cin >> N;

    // Please write your code here.
    cout << Fibo(N) % 10007;
    return 0;
}