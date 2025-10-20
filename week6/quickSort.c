#include <iostream>
using namespace std;

void quickSort(int a[], int l, int r) {
    int p = a[(l + r) / 2];
    int i = l, j = r;

    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep (QuickSort): ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
