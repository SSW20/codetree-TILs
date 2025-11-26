#include <iostream>
#include <cmath>
using namespace std;

int n;
int f[1001];

int Fibo(int N)
{
    if (f[N] != 0) return f[N];
    if (N <= 2) return f[N];
    else
    {
        int temp = (((Fibo(N - 1) * 2) % 1000000007) + ((Fibo(N - 2) * 3)) % 1000000007);
        for (int i = 0; i <= N - 3; ++i)
        {
            temp = (temp + 2 * f[i] % 1000000007) % 1000000007;
        }
        f[N] = temp;
    }
    return f[N];
}

int main() {
    cin >> n;

    // Please write your code here.
    f[1] = 2;
    f[2] = 7;
    f[0] = 1;
    cout << Fibo(n);
    return 0;
}
