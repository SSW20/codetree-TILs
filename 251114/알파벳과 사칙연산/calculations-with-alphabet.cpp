#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

string expr;
int ansMax = INT_MIN;
vector<int> alpha(6);

void Calc(int idx, int total)
{
    if (idx >= expr.size())
    {
        ansMax = max(ansMax, total);
        return;
    }
    char sign = expr[idx];
    char alp = expr[idx + 1];

    if (sign == '+')
    {
        if (alpha[alp - 'a'] == 0)
        {
            for (int i = 1; i <= 4; ++i)
            {
                alpha[alp - 'a'] = i;
                Calc(idx + 2, total + i);
                alpha[alp - 'a'] = 0;
            }
        }
        else
        {
            Calc(idx + 2, total + alpha[alp - 'a']);
        }
    }
    else if (sign == '-')
    {
        if (alpha[alp - 'a'] == 0)
        {
            for (int i = 1; i <= 4; ++i)
            {
                alpha[alp - 'a'] = i;
                Calc(idx + 2, total - i);
                alpha[alp - 'a'] = 0;
            }
        }
        else
        {
            Calc(idx + 2, total - alpha[alp - 'a']);
        }
    }
    else
    {
        if (alpha[alp - 'a'] == 0)
        {
            for (int i = 1; i <= 4; ++i)
            {
                alpha[alp - 'a'] = i;
                Calc(idx + 2, total * i);
                alpha[alp - 'a'] = 0;
            }
        }
        else
        {
            Calc(idx + 2, total * alpha[alp - 'a']);
        }
    }
}
int main() {
    cin >> expr;

    // Please write your code here.
    


    for (int i = 1; i <= 4; ++i)
    {
        alpha[expr[0] - 'a'] = i;
        Calc(1, i);
    }
    cout << ansMax;

    return 0;
}