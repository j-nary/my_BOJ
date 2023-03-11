//BOJ_1806 부분합 [골드 4]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, S; cin >> N >> S;
    int input; 
    for (int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }

    //구간합 구하기
    for (int i = 1; i < N; i++) {
        v[i] += v[i-1];
    }


    int lIdx = -1, rIdx = 0;
    int minLen = 100005;
    while(rIdx != N) {
        int sum = 0;
        if (lIdx < 0) sum = v[rIdx];
        else sum = v[rIdx] - v[lIdx];

        if (sum == N) {
            minLen = min(minLen ,rIdx - lIdx + 1);
        }

        if (sum > N) lIdx++;
        else rIdx++; 
    }

    if (minLen > 100000) cout << "0\n";
    else cout << minLen << '\n';

}