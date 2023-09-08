#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

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

    bool flag = (N % 2 == 1);
    if (N == 1) cout << v[0] * v[0] << '\n';
    else cout << v[0] * v[N - 1] << '\n';

}