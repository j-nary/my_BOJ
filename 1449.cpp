//BOJ_1449 수리공 항승 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> W;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, L; cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        W.push_back(input);
    }
    sort(W.begin(), W.end());
    int s = W[0];
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (L <= W[i] - s) {
            ans++;
            s = W[i];
        }
    }
    cout << ans << '\n';
}