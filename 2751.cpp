#include <iostream>

using namespace std;

int input[1000006];

void MergeSort (int[], int[], int, int);
void MergeTwoArea (int[], int[], int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    for (int i = 0; i < T; i++) cin >> input[i];

    // ���� ����� ���� �޸� �Ҵ�
    int *sortArr = new int[T+1];

    MergeSort(input, sortArr, 0, T-1);

    for (int i = 0; i < T; i++) cout << input[i] << '\n';
}

void MergeSort (int arr[], int sortArr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;   //�߰�����

        MergeSort(arr, sortArr, left, mid);
        MergeSort(arr, sortArr, mid + 1, right);     //����

        MergeTwoArea(arr, sortArr, left, mid, right);
    }
}

void MergeTwoArea (int arr[], int sortArr[], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;

    int sIdx = left;

    // ������ �� ������ ������ �� ��, sortArr�� ���
    while (fIdx <= mid && rIdx <= right) {
        if (arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];
        sIdx++;
    }

    // �� ���� �����Ͱ� ��� �̵��Ǿ� ������ �����͸� sortArr�� �̵�
    if (fIdx <= mid) 
        copy(arr + fIdx, arr + (mid+1), sortArr + sIdx);
    else if (rIdx <= right)
        copy(arr + rIdx, arr + (right+1), sortArr + sIdx);

    // �պ� ��� ������ �迭�� �Ű� ���
    for (int i = left; i <= right; i++) {
        arr[i] = sortArr[i];
    }
}