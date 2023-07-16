//BOJ_1654 랜선 자르기 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> len;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int K, N; cin >> K >> N;
    unsigned int left = 1, right = 1;
    for (int i = 0; i < K; i++) {
        int input; cin >> input;
        len.push_back(input);
        right = max(right, (unsigned int)input);
    }


    unsigned int ans = 0;
    while(left <= right) {
        unsigned int mid = (left + right) / 2;

        int cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += (len[i] / mid);
        }

        if (cnt >= N) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
}