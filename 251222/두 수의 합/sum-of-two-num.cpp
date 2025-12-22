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

        if (umap.find(arr[i]) == umap.end())
        {
            umap[arr[i]] = 1;
        }
        else
        {
            umap[arr[i]] += 1;
        }

    }
    
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (umap.find(k - arr[i]) != umap.end())
        {
            total += umap[k-arr[i]];
        }
    }

    cout << total / 2;


    return 0;
}