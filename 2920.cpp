//BOJ_2920 음계 [블론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int s; cin >> s;
    if (s == 1) {
        int tmp = 2;
        while(tmp != 9) {
            cin >> s;
            if (s == tmp) tmp++;
            else {
                cout << "mixed\n";
                return 0;
            }
        }
        cout << "ascending\n";
    } else if (s == 8) {
        int tmp = 7;
        while(tmp) {
            cin >> s;
            if (s == tmp) tmp--;
            else {
                cout << "mixed\n";
                return 0;
            }
        }
        cout << "descending\n";
    } else {
        cout << "mixed\n";
    }
}