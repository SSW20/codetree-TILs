#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

int N, G;
unordered_set<int> Groups[250001];
vector<int> personInGroups[100001];
unordered_set<int> Selected;
int main() {
    cin >> N >> G;
    int groupSize, person;
    for (int i = 0; i < G; i++) {
        cin >> groupSize;
        for (int j = 0; j < groupSize; j++) {
            cin >> person;
            Groups[i + 1].insert(person);
            personInGroups[person].push_back(i + 1);
        }
    }


    queue<int> q;
    q.push(1);
    Selected.insert(1);
    while (!q.empty())
    {
        int curPerson = q.front();
        q.pop();

        

        for (int group : personInGroups[curPerson])
        {
            Groups[group].erase(curPerson);
            if (Groups[group].size() == 1)
            {
                int lastPerson = *Groups[group].begin();
                if (Selected.find(lastPerson) == Selected.end())
                {
                    q.push(lastPerson);
                    Selected.insert(lastPerson);
                }
            }
        }
    }
    

    cout << Selected.size();

    return 0;
}

