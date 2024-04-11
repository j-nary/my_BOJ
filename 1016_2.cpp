//BOJ_1016 제곱 ㄴㄴ 수 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool chk[(int)1e6 + 1];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int Min, Max;
    cin >> Min >> Max;
    for (int i = 2; i * i <= Max; i++) {
        long long tmp = Min / (i * i);
        // if (!(tmp % (Min / (i * i)))) tmp++;
        if (tmp * (i * i) < Min) tmp++;
        while (tmp * (i * i) <= Max) {
            chk[tmp * (i * i) - Min] = true;
            tmp++;
        }
    }

    int ans = 0;
    for (int i = 0; i <= Max - Min; i++) {
        if (!chk[i]) ans++;
    }
    cout << ans << '\n';
}
