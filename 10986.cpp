//BOJ_10986 나머지 합 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long MOD[1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int ip; cin >> ip;
        sum += ip;
        MOD[sum % M]++;
    }

    //pSum[e] % M == pSum[s - 1] % M
    long long ans = 0;
    for (int i = 0; i < M; i++) {
        ans += (MOD[i] * (MOD[i] - 1) / 2);
    }
    cout << ans + MOD[0] << '\n';
}