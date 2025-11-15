#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
bool gFlag = true;
bool Check(int startX, int startY, int cnt)
{
    for (int i = 0; i < cnt; ++i)
    {
        if (v[startX + i] != v[startY + i]) return true;
    }
    return false;
}

bool divide(int checkSize)
{
    bool flag = true;
    int length = v.size() / 2;
    for (int i = 0; i + checkSize * 2 <= v.size(); ++i)
    {
        if (flag == false) return flag;
        flag = Check(i, i + checkSize, checkSize);
    }
    return flag;
}

bool Possible()
{
    bool flag = true;
    int length = v.size() / 2;
    if (v.size() <= 1) return true;
    for (int i = 1; i  <= length; ++i)
    {
        if (flag == false) return flag;
        flag = divide(i);
    }
    return flag;
}

void Calc(int cnt)
{
    if (cnt == n && gFlag)
    {
        for (int x : v) cout << x;
        cout << '\n';
        gFlag = false;
    }
    if (!gFlag) return;
    for (int i = 4; i <= 6; ++i)
    {
        v.push_back(i);
        if (Possible())
        {
            Calc(cnt + 1);
            v.pop_back();
        }
        else
        {
            v.pop_back();
        }
    }
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    // Please write your code here.
    Calc(0);
    return 0;
}
