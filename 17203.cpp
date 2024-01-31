#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> input;
vector<int> pSum;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int M; cin >> M;
    for (int i = 1; i <= N; i++) {
        int ip; cin >> ip;
        input.push_back(ip);
    }
    pSum.push_back(0);
    for (int i = 1; i <= N; i++) {
        pSum.push_back(abs(input[i] - input[i - 1]));
    }

    for (int i = 1; i <= N; i++) {
        pSum[i] += pSum[i - 1];
    }
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        e--;
        int ans = pSum[e];
        if (s > 1) ans -= pSum[s - 1];
        cout << ans << '\n';
    }
}

// 0 1 1 1 11
// 100 101 382 573
// 0 1 281 191 573