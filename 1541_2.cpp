//BOJ_1541 잃어버린 괄호 [실버 2]

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string ip; cin >> ip;
    int sum = 0, temp = 0, i = 0;
    bool minus = false;

    while (i <= ip.size()) {
        if (ip[i] == '-' || ip[i] == '+' || i == ip.size()) {
            if (minus) {
                sum -= temp;
            } else {
                sum += temp;
            }
            temp = 0;
            if (ip[i] == '-') {
                minus = true;
            }
        } else {
            temp = temp * 10 + (ip[i] - '0');
        }
        i++;
    }

    cout << sum << '\n';
    return 0;
}
