//BOJ_2309 일곱 난쟁이 [브론즈 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> v;
    for (int i = 0; i < 9; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    int a = 0, b = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            int sum = 0;
            for (int k = 0; k < 9; k++) {
                if (k == i || k == j) continue;
                sum += v[k];
            }
            if (sum == 100) {
                a = i; b = j;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i == a || i == b) continue;
        cout << v[i] << '\n';
    }
}