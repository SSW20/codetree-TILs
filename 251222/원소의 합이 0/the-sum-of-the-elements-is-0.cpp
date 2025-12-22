#include <iostream>
#include <unordered_map>
using namespace std;

int n;
int A[5000];
int B[5000];
int C[5000];
int D[5000];

unordered_map<long long, long long> umap1;
unordered_map<long long, long long> umap2;
unordered_map<long long, long long> umap;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    for (int i = 0; i < n; i++) cin >> C[i];

    for (int i = 0; i < n; i++) cin >> D[i];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            umap1[A[i] + B[j]]++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            umap2[C[i] + D[j]]++;

    int total = 0;
    for (auto it1 = umap1.begin(); it1 != umap.end(); it1++)
        for (auto it2 = umap2.begin(); it2 != umap.end(); it2++)
        {
            if (it1->first + it2->first == 0)
            {
                total += it1->second * it2->second;
            }
        }

    cout << total;
    return 0;
}
