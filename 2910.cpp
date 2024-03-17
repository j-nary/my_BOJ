//BOJ_2910 빈도 정렬 [실버 3]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

map<int, int> idx;
map<int, int> cnt;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, C;
    cin >> N >> C;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
        if (idx.find(tmp) == idx.end()) idx[tmp] = i;
        cnt[tmp]++;
    }

    sort(v.begin(), v.end(), [&](int a, int b) {
        if (cnt[a] == cnt[b]) return idx[a] < idx[b];
        return cnt[a] > cnt[b];
    });

    // v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}