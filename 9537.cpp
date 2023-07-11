//BOJ_9537 잘생긴 GCD [플래티넘 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;
ll A[100005];

ll gcd(ll a, ll b) {
    ll c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll Solve(int s, int e) {
    if (s >= e) return A[s];
    int mid = (s + e) / 2;
    ll res = max(Solve(s, mid - 1), Solve(mid + 1, e));

    vector<pair<ll, int>> left, right;
    left.push_back({A[mid], mid});
    right.push_back({A[mid], mid});

    for (int i = mid - 1; i >= s; i--) {
        ll g = gcd(left.back().first, A[i]);
        if (g == left.back().first) left.back().second = i;
        else left.push_back({g, i});
    }

    for (int i = mid + 1; i <= e; i++) {
        ll g = gcd(right.back().first, A[i]);
        if (g == right.back().first) right.back().second = i;
        else right.push_back({g, i});
    }

    for (int i = 0; i < left.size(); i++) {
        ll g1 = left[i].first;
        ll le = left[i].second;
        for (int j = 0; j < right.size(); j++) {
            ll g2 = right[j].first;
            ll ri = right[j].second;
            res = max(res, (ll)(gcd(g1, g2) * (ri - le + 1)));
        }
    }

    return res;
}
void test_case() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << Solve(0, N - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}