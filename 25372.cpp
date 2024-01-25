#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test_case() {
    string s;
    cin >> s;
    if (s.size() >= 6 && s.size() <= 9) cout << "yes\n";
    else cout << "no\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}