//BOJ_2473 세 용액
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    //N값이 용액문제에 비해 줄어든거면 시간초과나진 않을 듯 !?!?
    int resX = 0, resY = 1, resM = v[2], sIdx, eIdx;
    long long tmp = abs(v[0] + v[1] + v[2]);
    for (int i = 0; i < N; i++) {
        int idx = v[i];

        if (i >= 2) {
            sIdx = 0, eIdx = i - 1;
            while(sIdx < eIdx) {
                long long sum = v[sIdx] + v[eIdx] + idx;
                if (tmp > abs(sum)) {
                    resX = sIdx;
                    resY = eIdx;
                    resM = idx;
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
        }

        if (i < N - 2) {
            sIdx = i + 1, eIdx = N - 1;
            while(sIdx < eIdx) {
                long long sum = v[sIdx] + v[eIdx] + idx;
                if (tmp > abs(sum)) {
                    resX = sIdx;
                    resY = eIdx;
                    resM = idx;
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
        }
    }

    vector<int> res;
    res.push_back(v[resX]);
    res.push_back(v[resY]);
    res.push_back(resM);
    sort(res.begin(), res.end());

    for (int i = 0; i < 3; i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
}