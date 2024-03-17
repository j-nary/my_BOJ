//BOJ_11652 카드 [실버 4]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

map<long long, int> m;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int maxCd = 0;
    for (int i = 0; i < N; i++) {
        long long cd; cin >> cd;
        m[cd]++;
        maxCd = max(maxCd, m[cd]);
    }

    for (auto a : m) {
        if (a.second == maxCd) {
            cout << a.first << '\n';
            break;
        }
    }
}