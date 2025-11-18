#include <iostream>
#include <climits>
using namespace std;

int n;
int A[10][10];
int ansMinX = INT_MAX;
int visitedX[10];


void CalcX(int cnt, int total, int lastCity)
{
    if (cnt == n - 1)
    {
        if (A[lastCity][0] > 0)
        {
            total += A[lastCity][0];
            ansMinX = min(ansMinX, total);
        }
        return;
    }

    visitedX[lastCity] = 1;
    for (int i = 0; i < n; ++i)
    { 
        if (visitedX[i] || A[lastCity][i] == 0) continue;
        CalcX(cnt + 1, total + A[lastCity][i], i);
        visitedX[i] = 0;
    }

    
}



int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    CalcX(0, 0, 0);
    // Please write your code here.
    cout << ansMinX;
    return 0;
}
