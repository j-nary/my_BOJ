//BOJ_28601 축제 부스 기획하기 3
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    double S;
    cin >> S;

    double ans = 2 * sqrt(S);
    cout << ceil(ans) << endl;

    return 0;
}