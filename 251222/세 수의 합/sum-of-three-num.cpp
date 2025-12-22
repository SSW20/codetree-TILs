#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

long long int n, k;
long long int arr[100000];
unordered_map<long long int, long long int> umap;

int main() {
    // Please write your code here.
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        long long int diff = k - arr[i];

        for (int j = i + 1; j < n; ++j)
        {
            if (i == j) continue;
            long long int diff2 = diff - arr[j];

            total += umap[diff2];

            umap[arr[j]]++;
        }
        umap.clear();
    }
    cout << total;


    return 0;
}