#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test_case() {
    int a, b; cin >> a >> b;
    printf("You get %d piece(s) and your dad gets %d piece(s).\n", a / b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}