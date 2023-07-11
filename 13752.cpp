//BOJ_13752 히스토그램 [브론즈 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cout << "=";
        }
        cout << '\n';
    }
}