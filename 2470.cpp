//BOJ_2470 두 용액 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;
vector<ll> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        ll ip; cin >> ip;
        v.push_back(ip);
    }

    sort(v.begin(), v.end(), [](const ll& a, const ll&b) {
        return abs(a) < abs(b);
    });

    ll res = 1e18;
    pair<ll, ll> ans;
    for (int i = 0; i < N - 1; i++) {
        int sum = abs(v[i] + v[i + 1]);
        if (res > sum) {
            res = sum;
            ans = {v[i], v[i + 1]};
        }
    }

    if (ans.first > ans.second) {
        swap(ans.first, ans.second);
    }
    cout << ans.first << " " << ans.second << '\n';
}