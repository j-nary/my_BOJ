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
        int mid = (left + right) / 2;   //중간지점

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);     //분할

        MergeTwoArea(arr, left, mid, right);
    }
}

void MergeTwoArea (int arr[], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;

    // 병합 결과를 담을 메모리 할당
    int *sortArr = new int[right+1];
    int sIdx = left;

    // 병합할 두 영역의 데이터 비교 후, sortArr에 담기
    while (fIdx <= mid && rIdx <= right) {
        if (arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];
        sIdx++;
    }

    // 한 쪽의 데이터가 모두 이동되어 나머지 데이터를 sortArr로 이동
    if (fIdx <= mid) 
        copy(arr + fIdx, arr + (mid+1), sortArr + sIdx);
    else if (rIdx <= right)
        copy(arr + rIdx, arr + (right+1), sortArr + sIdx);

    // 합병 결과 기존의 배열에 옮겨 담기
    for (int i = left; i <= right; i++) {
        arr[i] = sortArr[i];
    }

    // 메모리 해제 (참고로, 메모리 할당, 해제는 시간이 많이 소요돼 비효율적임.)
    delete(sortArr);
}