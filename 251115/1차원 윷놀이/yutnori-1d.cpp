#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> distances;
vector<int> horses;
vector<int> scores;
int scoreMax = -1;

int GetScore()
{
    int count = 0;
    for (int x : scores) { if (x == 1) ++count; }
    return count;
}


void Race(int cnt)
{
    if (cnt == n)
    {
        scoreMax = max(scoreMax, GetScore());
        return;
    }

    for (int i = 0; i < k; ++i)
    {
        horses[i] += distances[cnt];
        if (horses[i] >= m) scores[i] = 1;
        Race(cnt + 1);
        horses[i] -= distances[cnt];
        if (horses[i] < m) scores[i] = 0;
    }
}


int main() 
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; 
        distances.push_back(x);
    }
    horses.assign(k, 1);
    scores.assign(k, 0);

    // Please write your code here.
    Race(0);

    cout << scoreMax;

    return 0;
}
