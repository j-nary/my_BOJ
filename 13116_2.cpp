#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A, B;

void test_case() {
    cin >> A >> B;
    while(1) {
        if (A == B) {
            cout << A * 10 << '\n';
            break;
        }
        else if (A > B) A /= 2;
        else B /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}