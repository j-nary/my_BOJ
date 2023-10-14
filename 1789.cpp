//BOJ_1789 수들의 합 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    long long S; cin >> S;
    int tmp = 1, cnt = 0;
    long long sum = 0;

    while(1) {
        sum += tmp;
        cnt++;
        tmp++;
        if (sum > S) {
            cnt--;
            break;
        }
    }
    cout << cnt << '\n';
}