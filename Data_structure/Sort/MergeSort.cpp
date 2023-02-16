#include <iostream>

using namespace std;

void MergeSort (int[], int, int);
void MergeTwoArea (int[], int, int, int);

int main() {
    int arr[8] = {5, 1, 3, 7, 8, 2, 4, 6};

    MergeSort(arr, 0, 7);

    for (int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

void MergeSort (int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;   //�߰�����

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);     //����

        MergeTwoArea(arr, left, mid, right);
    }
}

void MergeTwoArea (int arr[], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;

    // ���� ����� ���� �޸� �Ҵ�
    int *sortArr = new int[right+1];
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

    // �޸� ���� (�����, �޸� �Ҵ�, ������ �ð��� ���� �ҿ�� ��ȿ������.)
    delete(sortArr);
}