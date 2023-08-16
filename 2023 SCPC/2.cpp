//딸기 수확 로봇
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;
using ll = long long;

map <ll, ll> m;
ll N, D;
map<ll, ll>::iterator it;
ll minD, maxD;
ll ans;

//지나온 거리, 현재 위치 좌표, 가진 딸기 개수
void dfs(ll dist, ll loc, ll hav) {
    if (dist > D) return;

    it = m.find(loc);
    if (it != m.end()) {
        hav += (it -> second);
        ans = max(ans, hav);
    }

    if (loc > minD) dfs(dist + 1, loc - 1, hav);
    if (loc < maxD) dfs(dist + 1, loc + 1, hav);
}

void test_case() {
    m.clear();
    cin >> N >> D; ans = 0;
    minD = 1e9 + 2; maxD = 0;
    for (int i = 0; i < N; i++) {
        ll input; cin >> input;
        if (input < minD) minD = input;
        // if (input < 0) minS = max(input, minS);
        if (input > maxD) maxD = input;
        // if (input > 0) maxS = min(input, maxS);

        it = m.find(input);
        if (it != m.end()) {
            it -> second++;
        } else {
            m.insert({input, 1});
        }
    }

    // dfs(minS, -minS, 0);
    // dfs(maxS, maxS, 0);
    dfs(0, 0, 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << '\n';
        test_case();
        cout << ans << '\n';
    }
}