#include <iostream>

using namespace std;

int n;
unsigned long long int f[20];

int main() {
    cin >> n;

    // Please write your code here.
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    f[3] = 5;
    
    for (int i = 3; i <= n; ++i)
    {
        unsigned long long int temp = 0;
        for (int k = 0; k < i; ++k)
        {
            temp += f[k] * f[i-1-k];
        }
        f[i] = temp;
    }

    cout << f[n];
    return 0;
}
