#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� �켱���� ť
vector<int> v;
void MergeSort (int, int);
void MergeTwoArea (int, int, int);
int main() {
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;    //Q�� ������ ������ ����

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
		
        // �� ���� �������� ����
        MergeSort(left, mid);
        MergeSort(mid + 1, right);

        MergeTwoArea(left, mid, right);
    }
}

void MergeTwoArea (int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;

    // ���� ����� ���� �޸� �Ҵ�
    int *sortArr = new int[right+1];
    int sIdx = left;

    // ������ �� ������ ������ �� ��, sortArr�� ���
    while (fIdx <= mid && rIdx <= right) {
        if (v[fIdx] <= v[rIdx])
            sortArr[sIdx] = v[fIdx++];
        else
            sortArr[sIdx] = v[rIdx++];
        sIdx++;
    }

    // �� ���� �����Ͱ� ��� �̵��Ǿ� ������ �����͸� sortArr�� �̵�
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

    // �պ� ��� ������ �迭�� �Ű� ���
    for (int i = left; i <= right; i++) {
        v[i] = sortArr[i];
    }

    // �޸� ���� (�����, �޸� �Ҵ�, ������ �ð��� ���� �ҿ�� ��ȿ������.)
    delete(sortArr);
}