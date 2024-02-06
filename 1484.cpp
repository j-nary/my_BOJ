//BOJ_1484 다이어트 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int G; cin >> G;

    int left = 1, right = 1;
    bool flag = true;
    while (1) {
        int tmp = right*right - left*left;

        if (right - left == 1 && tmp > G) break;
        if (tmp >= G) left++;
        else right++;

        if (tmp == G) {
            cout << right << '\n';
            flag = false;
        }
    }

    if (flag) cout << -1 << '\n';
}