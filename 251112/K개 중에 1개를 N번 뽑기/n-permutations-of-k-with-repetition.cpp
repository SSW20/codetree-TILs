#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> v;
void Select(int n)
{
    if (n == N + 1) 
    { 
        for (int i : v) { cout << i << ' '; }
        cout << '\n';
        v.pop_back(); 
        return; 
    }

    for (int i = 1; i <= K; ++i)
    {
        v.push_back(i);
        Select(n + 1);
    }
    v.pop_back();
}

int main() {
    cin >> K >> N;
    Select(1);
    // Please write your code here.

    return 0;
}
