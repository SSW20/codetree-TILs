#include <iostream>

using namespace std;

int n;
int globalCount = 0;
void Caculate(int k)
{
    if (k == n) { ++globalCount; return; }
    if (k > n) { return; }
    for (int i = 1; i <= 4; ++i)
    {
        Caculate(k + i);
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    Caculate(0);
    cout << globalCount;
    return 0;
}
