#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void Calc(int cnt, int idx)
{
    if (cnt == M)
    {
        for (int x : v)
            cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i <= N; ++i)
    {
        v.push_back(i);
        Calc(cnt + 1, i + 1);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;

    Calc(0, 1);
    return 0;
}
