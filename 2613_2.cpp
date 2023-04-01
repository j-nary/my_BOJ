//BOJ_2613 숫자구슬 [골드 2]
//Parametric Searching으로 풀기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M; 
vector<int> gu;
vector<int> promising(int max) {
    int cnt = 1;
    int sum = 0;
    vector<int> idx;
    for (int i = 0; i < N; i++) {
        sum += gu[i];
        if (sum > max) {
            idx.push_back(i-1);
            cnt++;
            sum = 0;
            i--;
        }
    }
    if (cnt == M) {
        idx.push_back(N - 1);
        return idx;
    } else if (cnt < M) {
        int sz = M - cnt;
        while (idx.size() != M - 1) {
            if (idx.back() == idx.size() - 1) {
                idx.push_back(idx.size());
                continue;
            }
            for (int i = 0; i < idx.size(); i++) {
                if (idx.size() == M - 1) break;
                if (i == 0 && idx[i] >= 1) {
                    idx[i]--;
                    idx.insert(idx.begin() + i + 1, idx[i] + 1);
                    i--;
                } else if (idx[i] - idx[i - 1] >= 2) {
                    idx[i]--;
                    idx.insert(idx.begin() + i + 1, idx[i] + 1);
                    i--;
                }
            }
        }
        idx.push_back(N - 1);
        return idx;
    } else {
        idx.clear();
        return idx;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    int input, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> input;
        sum += input;
        gu.push_back(input);
    }

    int left = *max_element(gu.begin(), gu.end());
    int right = sum;

    int maxSum = 1e9;
    vector<int> resIdx;
    while(left <= right) {
        int mid = (left + right) / 2;

        vector<int> promised = promising(mid);
        if (promised.size() == 0) {
            left = mid + 1;
            continue;
        }

        if (maxSum > mid) {
            maxSum = mid;
            right = mid - 1;
            resIdx = promised;
        }
    }

    cout << maxSum << '\n';
    for (int i = 0; i < resIdx.size(); i++) {
        if (i == 0) {
            cout << resIdx[i] + 1 << " ";
        } else {
            cout << resIdx[i] - resIdx[i - 1] << " ";
        }
    }
    cout << '\n';
}