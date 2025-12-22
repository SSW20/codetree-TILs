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


    int total = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            umap2[C[i] + D[j]]++;
            total += umap1[-(C[i] + D[j])];
        }



    cout << total;
    return 0;
}
