#include <iostream>

using namespace std;
using ll = long long;

int main() {

    ll dp[102];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;

    for (ll i = 5; i < 102; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }

    int T;
    cin >> T;
    ll idx;

    while (T--) {        
        cin >> idx;
        cout << dp[idx] << endl;
    }
    return 0;
}