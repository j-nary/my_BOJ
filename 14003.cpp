//BOJ_14003 가장 긴 증가하는 부분 수열 5
#include <bits/stdc++.h>
#include <iostream>

#define INF 1e9;
using namespace std;

vector<int> v;
vector<int> LIS;
int P[1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    LIS.push_back(v[0]);
    P[0] = 0;
    for (int i = 1; i < N; i++) {
        int idx = lower_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
        if (idx == LIS.size()) {
            LIS.push_back(v[i]);
        } else {
            LIS[idx] = v[i];
        }
        P[i] = idx;
    }

    int cnt = LIS.size();
    cout << cnt-- << '\n';

    vector<int> ans;
    for (int i = N - 1; i >= 0; i--) {
        if (P[i] == cnt) {
            ans.push_back(v[i]);
            cnt--;
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}