//BOJ_2003 수들의 합 2 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> v;
long long sum[10004];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    sum[0] = v[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i-1] + v[i];
    }

    int tmp = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (i == 0) tmp = sum[j];
            else tmp = sum[j] - sum[i-1];
            if (tmp == M) ans++;
        }
    }
    cout << ans << '\n';
}