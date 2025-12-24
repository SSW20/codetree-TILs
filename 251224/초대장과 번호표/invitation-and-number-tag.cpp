#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int N, G;
unordered_set<int> NotSelected[250001];
unordered_set<int> Selected;

int main() {
    cin >> N >> G;
    int groupSize, person;
    for (int i = 0; i < G; i++) {
        cin >> groupSize;
        for (int j = 0; j < groupSize; j++) {
            cin >> person;
            if (j == 0) Selected.insert(person);
            else NotSelected[i + 1].insert(person);
        }
    }

    for (int i = 1; i <= G; ++i)
    {
        for (auto it = Selected.begin(); it != Selected.end(); ++it)
        {
            if (NotSelected[i].size() == 0) break;
            if (NotSelected[i].find(*it) != NotSelected[i].end())
            {
                NotSelected[i].erase(*it);
            }
        }

        if (NotSelected[i].size() == 1)
        {
            Selected.insert(*NotSelected[i].begin());
        }
    }

    cout << Selected.size();

    return 0;
}

