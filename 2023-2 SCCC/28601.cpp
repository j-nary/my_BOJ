//BOJ_28601 축제 부스 기획하기 3
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    long long S;
    cin >> S;

    if (S == 0) {
        cout << 0 << '\n';
        return 0;
    }
    long long ans = 2 * sqrt(S);
    //sqrt 오차
    while(ans * ans < 4 * S) ans++;
    while((ans - 1) * (ans - 1) > 4 * S) ans--;

    cout << ans << endl;

    return 0;
}