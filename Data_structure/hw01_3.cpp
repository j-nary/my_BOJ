#include <iostream>

using namespace std;
int cnt;

int BinarySearch(int *, const int, const int, const int);
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }

    int x;
    cin >> x;

    cout << BinarySearch(arr, x, 0, n-1) << endl;
    cout << cnt << endl;
    delete [] arr;
}
int BinarySearch(int *a, const int x, const int left, const int right) {
    if(left <= right) {
        int middle = (left + right)/2;
        cnt++;
        if (x < a[middle]) return BinarySearch(a, x, left, middle-1);
        else if (x > a[middle]) return BinarySearch(a, x, middle+1, right);
        return middle;
    }
    return -1;
}