#include <iostream>
#include <algorithm>

using namespace std;

int BinarySearch(int *a, const int x, const int left, const int right) {
    if (left <= right) {
        int middle = (left + right) / 2;
        if (x < a[middle])
            return BinarySearch(a, x, left, middle-1);
        else if (x > a[middle])
            return BinarySearch(a, x, middle+1, right);
        else
            return middle;
    }

    return -1;
}

int main() {
    int num;
    scanf("%d", &num);
    int *arr = new int[num];
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+num);

    int xnum;
    scanf("%d", &xnum);
    int *xrr = new int[xnum];

    int tmp = 0;
    for (int i = 0; i < xnum; i++) {
        scanf("%d", &xrr[i]);
        tmp = BinarySearch(arr, xrr[i], 0, num-1);
        if (tmp != -1)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}

