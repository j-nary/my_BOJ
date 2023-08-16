//BOJ_2180 소방서의 고민 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [](auto a, auto b) {
        return ;
    });

}