#include <iostream>

using namespace std;

int n;
int arr[100000];
int partition(int start, int end);
void quickSort(int start, int end)
{
    int pivot = partition(start, end);
    if (start < pivot - 1)
    {
        quickSort(start, pivot - 1);
    }
    if (pivot < end)
    {
        quickSort(pivot, end);
    }
}

int partition(int start, int end)
{
    int pivot = arr[(start + end) / 2];
    while (start <= end)
    {
        while (arr[start] < pivot) start++;
        while (arr[end] > pivot) --end;


        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp; start++; --end;
    }

    return start;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    quickSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
