#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test_case() {
    int a, b;
    long long num = 1;
    cin >> a >> b;
    for (int i = 0; i < b; i++) {
        num *= a;
        num %= 10;
    }
    if (num % 10)
        cout << num % 10 << '\n';
    else
        cout << 10 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}