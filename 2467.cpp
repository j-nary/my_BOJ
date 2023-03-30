//BOJ_2467 용액 [골드 5]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> v; //input
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    int sIdx = 0, eIdx = N - 1;
    int resX = sIdx, resY = eIdx;
    long long tmp = abs(v[sIdx] + v[eIdx]);
    while(sIdx < eIdx) {
        long long sum = v[sIdx] + v[eIdx];
        if (tmp > abs(sum)) {
            resX = sIdx;
            resY = eIdx;
            tmp = abs(sum);
        }

        if (sum == 0) {
            resX = sIdx;
            resY = eIdx;
            break;
        } else if (sum > 0) {
            eIdx--;
        } else if (sum < 0) {
            sIdx++;
        }
    }

    if (resX <= resY) {
        cout << v[resX] << ' ' << v[resY] << '\n';
    } else {
        cout << v[resY] << ' ' << v[resX] << '\n';
    }

}