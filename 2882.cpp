//BOJ_2882 점수 계산 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<pair<int, int>> v;
    for (int i = 1; i <= 8; i++) {
        int ip; cin >> ip;
        v.push_back({ip, i});
    }

    sort(v.begin(), v.end());
    int sum = 0;
    vector<int> idx;
    for (int i = 3; i <= 7; i++) {
        idx.push_back(v[i].second);
        sum += v[i].first;
    }
    cout << sum << '\n';
    sort(idx.begin(), idx.end());
    for (int i = 0; i < idx.size(); i++) {
        cout << idx[i] << " ";
    }
    cout << '\n';
}