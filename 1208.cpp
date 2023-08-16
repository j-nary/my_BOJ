//BOJ_1208 부분수열의 합 2 [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int N, S;
vector<int> v;
map<int, int> sum;
long long ans;

void leftSum(int idx, int s) {
    if (idx == N / 2) {
        sum[s]++;
        return;
    }
    leftSum(idx + 1, s);
    leftSum(idx + 1, s + v[idx]);
}

void rightSum(int idx, int s) {
    if (idx == N) {
        ans += sum[S - s];
        return;
    }
    rightSum(idx + 1, s);
    rightSum(idx + 1, s + v[idx]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    leftSum(0, 0);
    rightSum(N / 2, 0);

    if (S == 0) cout << ans - 1 << '\n';
    else cout << ans << '\n';
}