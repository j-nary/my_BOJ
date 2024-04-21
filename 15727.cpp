//BOJ_15727 조별과제를 하려는데 조장이 사라졌다 [브론즈 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int L; cin >> L;
    int ans = L / 5;
    if (L % 5) ans++;
    cout << ans << '\n';
}