//BOJ_1695 팰린드롬 만들기 [골드 4]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[5003][5003];

vector<int> v;
int dpSolve(int s, int e) {
    if (s > e) return 0;
    if (dp[s][e] != -1) return dp[s][e];

    if (v[s] == v[e]) {
        return dp[s][e] = dpSolve(s + 1, e - 1);
    } else {
        return dp[s][e] = min(dpSolve(s, e - 1), dpSolve(s + 1, e)) + 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    memset(dp, -1, sizeof(dp));
    cout << dpSolve(0, N - 1) << '\n';
}