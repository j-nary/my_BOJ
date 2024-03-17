//BOJ_17427 약수의 합 2 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        int tmp = N / i;
        tmp *= i;
        ans += tmp;
    }
    cout << ans << '\n';
}