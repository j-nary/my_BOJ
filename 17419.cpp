//BOJ_17419 비트가 넘쳐흘러 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    int cnt = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '1') cnt++;
    }

    cout << cnt << '\n';
}