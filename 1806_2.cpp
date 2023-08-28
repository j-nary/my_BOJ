//BOJ_1806 부분합 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int pSum[100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, S; cin >> N >> S;
    cin >> pSum[0];
    for (int i = 1; i < N; i++) {
        cin >> pSum[i];
        pSum[i] += pSum[i - 1];
    }

    int start = -1, end = 0;
    int ans = 1e9;
    int tmp = 0;
    while(start <= end) {
        if (end > N) break;

        if (start == -1) tmp = pSum[end];
        else tmp = pSum[end] - pSum[start];

        if (tmp >= S) {
            ans = min(ans, end - start);
            start++;
        }
        else end++;
    }
    if (ans != 1e9) cout << ans << '\n';
    else cout << 0 << '\n';
}