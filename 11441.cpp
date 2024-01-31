#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> pSum;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    pSum.push_back(0);
    for (int i = 1; i <= N; i++) {
        int ip; cin >> ip;
        pSum.push_back(pSum[i - 1] + ip);
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        int ans = pSum[e];
        if (s > 1) ans -= pSum[s - 1];
        cout << ans << '\n';
    }
}