//BOJ_1026 보물 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> A;
vector<int> B;
vector<pair<int, int>> tmp;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int ip;
    for (int i = 0; i < N; i++) {
        cin >> ip;
        A.push_back(ip);
    }
    for (int i = 0; i < N; i++) {
        cin >> ip;
        B.push_back(ip);
        tmp.push_back({ip, i});
    }
    sort(A.begin(), A.end(), greater<int>());
    sort(tmp.begin(), tmp.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (B[tmp[i].second] * A[i]);
    }

    cout << ans << '\n';
}