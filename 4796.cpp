//BOJ_4796 캠핑 [브론즈 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int test_case() {
    int L, P, V; cin >> L >> P >> V;
    if (L == 0 && P == 0 && V == 0) return 0;

    int ans = 0;
    while(V) {
        if (V < 0) break;
        if (V <= L) {
            ans += V;
            break;
        }

        V -= P;
        ans += L;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int t = 1; ; t++) {
        int ans = test_case();
        if (!ans) break;
        cout << "Case " << t << ": " << ans << '\n';
    }
}