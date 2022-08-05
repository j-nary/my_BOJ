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
        int mid = (left + right) / 2;   //중간지점

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);     //분할

        MergeTwoArea(arr, left, mid, right);
    }
}

void MergeTwoArea (int arr[][2], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;

    // 병합 결과를 담을 메모리 할당
    int **sortArr = new int*[2];
    for (int i = 0; i < right + 1; i++)
        sortArr[i] = new int[right+1];

    int sIdx = left;

    // 병합할 두 영역의 데이터 비교 후, sortArr에 담기
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

    // 한 쪽의 데이터가 모두 이동되어 나머지 데이터를 sortArr로 이동
    if (fIdx <= mid) 
        copy(arr + fIdx, arr + (mid+1), sortArr + sIdx);
    else if (rIdx <= right)
        copy(arr + rIdx, arr + (right+1), sortArr + sIdx);

    // 합병 결과 기존의 배열에 옮겨 담기
    for (int i = left; i <= right; i++) {
        arr[i][0] = sortArr[i][0];
        arr[i][1] = sortArr[i][1];
    }

    // 메모리 해제 (참고로, 메모리 할당, 해제는 시간이 많이 소요돼 비효율적임.)
    // for (int i = 0; i < 2; i++) {
    //     delete[] sortArr[i];
    // }
    // delete[] sortArr;
}