#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string expr;
int ansMax = -1;
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
    alpha[expr[0] - 'a'] = 4;


    Calc(1, 4);
    cout << ansMax;

    return 0;
}