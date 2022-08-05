#include <iostream>

using namespace std;
using ll = long long;
ll dp[102];

ll pado(ll N) {
    if (dp[N] != -1) return dp[N];
    if (N < 4)
        return dp[N] = 1;
    else if (N < 6)
        return dp[N] = 2;
    else
        return dp[N] = pado(N-1) + pado(N-5);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        for (ll i = 0; i < 102; i++)
            dp[i] = -1;
        ll N;
        cin >> N;
        cout << pado(N) << endl;
    }

    return 0;
}