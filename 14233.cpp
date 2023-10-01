//BOJ_14233 악덕 사장 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    int K = v[0];
    for (int i = 1; i < N; i++) {
        if (K * (i + 1) > v[i]) {
            K = v[i] / (i + 1);
        }
    }

    cout << K << '\n';
}