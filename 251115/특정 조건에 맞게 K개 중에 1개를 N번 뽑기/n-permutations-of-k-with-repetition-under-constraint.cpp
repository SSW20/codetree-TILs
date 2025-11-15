#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K, N;
vector<int> v;

bool Possible(int num)
{
    int count = 0;

    for (int i=0; i<v.size(); ++i)
    {
        if (v[i] != num) count = 0;
        else count++;
    }
    return !(count > 1);
}

void Calc(int num)
{
    if (num == N || v.size() == N)
    {
        for (int x : v) cout << x << ' ';
        cout << '\n';
        return;
    }


    for (int i = 1; i <= K; ++i)
    {
        if (Possible(i))
        {
            v.push_back(i);
            Calc(num + 1);
            v.pop_back();
        }
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    Calc(0);


    return 0;
}
