//BOJ_13305 주유소 [실버 3]

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

vector<int> price;
vector<int> dist;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int ip;
    for (int i = 0; i < N - 1; i++) {
        cin >> ip;
        dist.push_back(ip);
    }
    for (int i = 0; i < N; i++) {
        cin >> ip;
        price.push_back(ip);
    }

    int stnd = price[0];
    for (int i = 1; i < N; i++) {
        stnd = min(stnd, price[i]);
        price[i] = stnd;
    }

    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += (ll)price[i] * dist[i];
    }
    cout << ans << '\n';
}

// 3 3 3