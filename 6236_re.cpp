//BOJ_6236 용돈 관리 [실버 2]
// PS 시험 대비 다시 풀어보기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> my;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int minK = 0, maxK = 0;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        my.push_back(input);
        maxK += input;
        minK = max(minK, input);
    }

    int left = minK, right = maxK;
    int res = 1e9;
    while (left <= right) {
        int mid = (left + right) / 2;

        int cnt = 1;
        int had = mid;
        for (int i = 0; i < N; i++) {
            had -= my[i];
            if (had < 0) {
                cnt ++;
                had = mid - my[i];
            }
        }

        if (cnt <= M) {
            res = min(res, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res << '\n';
}