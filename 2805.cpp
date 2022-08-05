#include <iostream>

int BinarySearch(int *a, int *h, int M, const int left, const int right);
int HowMany(int *a, int size, int height);

int main() {
    int M, N;
    scanf("%d %d", &N, &M);
    int *arr = new int[N];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int *height = new int[sum];
    for (int i = 0; i < sum; i++)
        height[i] = i;
    int H = BinarySearch(arr, height, M, 0, sum);

    printf("%d", H);

    return 0;
}

int BinarySearch(int *a, int *h, int M, const int left, const int right) {
    if (left <= right) {
        int middle = (left + right) / 2;
        if (HowMany(a, M, middle) < M)
            return BinarySearch(a, h, M, left, middle-1);
        else if (HowMany(a, M, middle) > M)
            return BinarySearch(a, h, M, middle+1, right);
        else
            return middle;
    }

    return -1;
}

int HowMany(int *a, int size, int height) {
    int have = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > height)
            have += a[i] - height;
    }
    return have;
}