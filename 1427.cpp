#include <iostream>
#include <cstring>

using namespace std;

void MergeSort (int[], int[], int, int);
void MergeTwoArea (int[], int[], int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string pre; cin >> pre;
    int len = pre.length();
    
    // ���� ����� ���� �޸� �Ҵ�
    int *sortArr = new int[len];
    char *tmp = new char[len];
    int *input = new int[len];

    strcpy(tmp, pre.c_str());
    for (int i = 0; i < len; i++) {
        input[i] = (int)tmp[i];
    }
    MergeSort(input, sortArr, 0, len-1);

    for (int i = len-1; i >= 0; i--) cout << input[i]-48;
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