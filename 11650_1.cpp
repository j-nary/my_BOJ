#include <iostream>
#define MAX 100000

using namespace std;

int IdxSort[MAX + 5][2];
// long long Rank[MAX + 5][2];

void MergeSort (int [][2], int, int);
void MergeTwoArea (int [][2], int, int, int);

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> IdxSort[i][0] >> IdxSort[i][1];
    }

    MergeSort(IdxSort, 0, N);
    
    for (int i = 0; i < N; i++) {
        cout << IdxSort[i][0] << " " << IdxSort[i][1] << endl;
    }
}

void MergeSort (int arr[][2], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;   //�߰�����

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);     //����

        MergeTwoArea(arr, left, mid, right);
    }
}

void MergeTwoArea (int arr[][2], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;

    // ���� ����� ���� �޸� �Ҵ�
    int **sortArr = new int*[2];
    for (int i = 0; i < right + 1; i++)
        sortArr[i] = new int[right+1];

    int sIdx = left;

    // ������ �� ������ ������ �� ��, sortArr�� ���
    while (fIdx <= mid && rIdx <= right) {
        if (arr[fIdx][0] < arr[rIdx][0]) {
            sortArr[sIdx][0] = arr[fIdx][0];
            sortArr[sIdx][1] = arr[fIdx++][1];
        }            
        if (arr[fIdx][0] == arr[rIdx][0] && arr[fIdx][1] < arr[rIdx][1]) {
            sortArr[sIdx][0] = arr[fIdx][0];
            sortArr[sIdx][1] = arr[fIdx++][1];
        } 
        else {
            sortArr[sIdx][0] = arr[rIdx][0];
            sortArr[sIdx][1] = arr[rIdx++][1];
        }
        sIdx++;
    }

    // �� ���� �����Ͱ� ��� �̵��Ǿ� ������ �����͸� sortArr�� �̵�
    if (fIdx <= mid) 
        copy(arr + fIdx, arr + (mid+1), sortArr + sIdx);
    else if (rIdx <= right)
        copy(arr + rIdx, arr + (right+1), sortArr + sIdx);

    // �պ� ��� ������ �迭�� �Ű� ���
    for (int i = left; i <= right; i++) {
        arr[i][0] = sortArr[i][0];
        arr[i][1] = sortArr[i][1];
    }

    // �޸� ���� (�����, �޸� �Ҵ�, ������ �ð��� ���� �ҿ�� ��ȿ������.)
    // for (int i = 0; i < 2; i++) {
    //     delete[] sortArr[i];
    // }
    // delete[] sortArr;
}