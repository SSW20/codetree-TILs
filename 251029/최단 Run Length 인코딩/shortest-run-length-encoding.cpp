#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    // Please write your code here.
    int n = A.size();

    if (n == 1) { cout << 2; return 0; }
    char c[10];
    for (int i = 0; i < n; ++i)
    {
        c[i] = A[i];
    }
    int count = 1;
    int min = 99999;
    while (count < n)
    {
        string temp;
        char tempChar = c[n-1];
        for (int i = n-1; i > 0; --i)
        {
            c[i] = c[i - 1];
        }
        c[0] = tempChar;
        char flag = c[0];
        int cachedCount = 2;
        int alpCount = 1;
        for (int i = 1; i < n; ++i)
        {
            if (flag != c[i])
            {
               cachedCount += 3;
               flag = c[i];
               alpCount = 1;
            }
            alpCount++;
        }
        if (alpCount == 10) { min = 3; break; }
        if (cachedCount < min) min = cachedCount;
        ++count;
    }

    cout << min;

    return 0;
}
