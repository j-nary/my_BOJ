#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이중 우선순위 큐
vector<int> v;
void MergeSort (int, int);
void MergeTwoArea (int, int, int);
int main() {
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;    //Q에 적용할 연산의 개수

        while (k--) {
            char mode; cin >> mode;
            int input; cin >> input;
            if (mode == 'I') {
                v.push_back(input);
                MergeSort(0, v.size()-1);
            }
            else if (!v.empty()){
                if (input == 1)
                    v.erase(v.end()-1);
                else
                    v.erase(v.begin());
            }
        }

        if (v.empty())
            cout << "EMPTY" << '\n';
        else
            cout << v[v.size()]<< " " << v[0] << '\n';
    }
}

void MergeSort (int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
		
        // 두 개의 영역으로 분할
        MergeSort(left, mid);
        MergeSort(mid + 1, right);

        MergeTwoArea(left, mid, right);
    }
}

void MergeTwoArea (int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;

    // 병합 결과를 담을 메모리 할당
    int *sortArr = new int[right+1];
    int sIdx = left;

    // 병합할 두 영역의 데이터 비교 후, sortArr에 담기
    while (fIdx <= mid && rIdx <= right) {
        if (v[fIdx] <= v[rIdx])
            sortArr[sIdx] = v[fIdx++];
        else
            sortArr[sIdx] = v[rIdx++];
        sIdx++;
    }

    // 한 쪽의 데이터가 모두 이동되어 나머지 데이터를 sortArr로 이동
    if (fIdx <= mid) {
        for(int i = fIdx; i <= mid; i++) {
            v[i] = sortArr[sIdx++];
        }
    }
    else if (rIdx <= right) {
        for (int i = rIdx; i <= right; i++) {
            v[i] = sortArr[sIdx++];
        }
    }

    // 합병 결과 기존의 배열에 옮겨 담기
    for (int i = left; i <= right; i++) {
        v[i] = sortArr[i];
    }

    // 메모리 해제 (참고로, 메모리 할당, 해제는 시간이 많이 소요돼 비효율적임.)
    delete(sortArr);
}