//BOJ_15649 N과 M (1) [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
vector<int> v;
bool chk[10];

void per() {
    if (v.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (chk[i]) continue;
        v.push_back(i);
        chk[i] = 1;
        per();
        v.pop_back();
        chk[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    per();
}