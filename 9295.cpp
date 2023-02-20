#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test_case(int x) {
    int a, b; cin >> a >> b;
    cout << "Case " << x << ": " << a + b << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case(t);
    }
}