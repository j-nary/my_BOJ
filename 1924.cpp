//BOJ_1924 2007년 [브론즈 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string date[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int x, y; cin >> x >> y;
    int cnt = y;
    for (int i = 1; i < x; i++) {
        cnt += month[i];
    }
    cout << date[cnt % 7] << '\n';
}