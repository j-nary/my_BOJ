//BOJ_7795 먹을 것인가 먹힐 것인가 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test_case() {
    int N, M; cin >> N >> M;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int ip; cin >> ip;
        A.push_back(ip);
    }
    vector<int> B;
    for (int i = 0; i < M; i++) {
        int ip; cin >> ip;
        B.push_back(ip);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (B[j] >= A[i]) break;
            else ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}