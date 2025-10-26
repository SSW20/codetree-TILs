#include <iostream>

using namespace std;

int n;
int arr[100000];
void merge(int* temp, int start, int mid, int end);
void merge_sort(int* temp, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(temp, start, mid);
        merge_sort(temp, mid+1, end);
        merge(temp, start, mid, end);
    }
}

void merge(int* temp, int start, int mid, int end)
{
    for (int i = start; i <= end; ++i)
    {
        temp[i] = arr[i];
    }

    int p1 = start;
    int p2 = mid + 1;
    int index = start;

    while (p1 <= mid && p2 <= end)
    {
        if (temp[p1] < temp[p2])
        {
            arr[index] = temp[p1];
            p1++;
        }
        else
        {
            arr[index] = temp[p2];
            p2++;
        }
        ++index;
    }

    while (p1 <= mid)
    {
        arr[index] = temp[p1];
        ++index;
        ++p1;
    }
    while (p2 <= end)
    {
        arr[index] = temp[p2];
        ++index;
        ++p2;
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    int* temp = new int[n];

    merge_sort(temp, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
