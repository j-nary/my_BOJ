//BOJ_1351 무한 수열 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

map<long long, long long> m;
long long N, P = 1, Q = 1;

long long DP(long long N) {
    if (N == 0) return 1;
    if (m[N]) return m[N];

    return m[N] = DP(N/P) + DP(N/Q);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> P >> Q;
    cout << DP(N) << '\n';

}