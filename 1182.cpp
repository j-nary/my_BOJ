//BOJ_1182 부분수열의 합 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, S; cin >> N >> S;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    int ans = 0;
    int tmp = 1 << N;
    for (int i = 1; i < tmp; i++) {
        int sum = 0;
        int j = i;
        for (int k = 0; k < N; k++) {
            if (1 & j) sum += v[k];
            j = j >> 1;
            if (j == 0) break;
        }
        if (sum == S) ans++;
    }

    cout << ans << '\n';
}