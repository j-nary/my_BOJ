//BOJ_25312 200% Mixed Juice! [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> drink;
ll gcd(ll a, ll b) {
    ll c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int w, v; cin >> w >> v;
        drink.push_back({w, v});
    }
    sort(drink.begin(), drink.end(), [](auto a, auto b){
        return a.second * b.first > b.second * a.first;
    });
    

    ll sum = 0, ans = 0;
    ll p, q;
    for (int i = 0; i < N; i++) {
        if (sum + drink[i].first > M) {
            ll tmp = M - sum;
            p = drink[i].first * ans + drink[i].second * tmp;
            q = drink[i].first;
            tmp = gcd(p, q);
            p /= tmp;
            q /= tmp;
            cout << p << "/" << q << '\n';
            return 0;
        } else {
            sum += drink[i].first;
            ans += drink[i].second;
        }
    }
    cout << ans << "/1\n";
}