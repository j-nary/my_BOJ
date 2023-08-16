//BOJ_14908 구두 수선공 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node {
    long long T;
    long long S;
    int idx;
};
vector<node> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        long long T, S; cin >> T >> S;
        v.push_back({T, S, i});
    }
    stable_sort(v.begin(), v.end(), [](auto a, auto b) {
        return a.T * b.S < b.T * a.S;
    });

    for (int i = 0; i < N; i++) {
        cout << v[i].idx << " ";
    }
    cout << '\n';
}