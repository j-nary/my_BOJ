//BOJ_2230 수 고르기 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    int left = 0, right = 1;
    long long ans = 1e12;
    while (left < N && right < N) {
        long long tmp = v[right] - v[left];

        if (tmp < M) {
            right++;
        } else {
            ans = min(ans, tmp);
            left++;
        }
    }
    cout << ans << '\n';
}